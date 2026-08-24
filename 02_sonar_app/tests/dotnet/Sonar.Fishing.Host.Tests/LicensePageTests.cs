using Sonar.Fishing.Host.LicensePage;
using Sonar.Fishing.Host.Licensing;
using Sonar.Fishing.Host.SettingsPersistence;
using System.Windows;

namespace Sonar.Fishing.Host.Tests;

internal static class LicensePageTests
{
    internal static IEnumerable<TestCase> Create()
    {
        yield return new TestCase(
            "unvalidated_license_never_exposes_migration_group_copy",
            UnvalidatedLicenseNeverExposesMigrationGroupCopy);
        yield return new TestCase(
            "local_access_license_hides_activation_and_raw_feature_ids",
            LocalAccessLicenseHidesActivationAndRawFeatureIds);
    }

    private static void UnvalidatedLicenseNeverExposesMigrationGroupCopy()
    {
        var viewModel = new LicensePageViewModel(LicenseHostSettings.Default);

        TestAssert.True(!viewModel.HasValidatedLicense, "Default license became validated");
        TestAssert.Equal("—", viewModel.Subscription, "Migration group leaked into user-facing subscription");
        TestAssert.Equal("—", viewModel.ExpiresAt, "Missing expiry did not stay neutral");
    }

    private static void LocalAccessLicenseHidesActivationAndRawFeatureIds()
    {
        var activationCalled = false;
        var viewModel = new LicensePageViewModel(
            DeveloperFullAccessPolicy.VisibleLicense,
            (_, _) =>
            {
                activationCalled = true;
                throw new InvalidOperationException("activation_must_stay_inert");
            },
            LicensePagePresentation.LocalAccess);

        TestAssert.True(viewModel.HasValidatedLicense, "Local access was not active");
        TestAssert.Equal("Локальный доступ", viewModel.StatusText,
            "Owner-facing status exposed technical authority terminology");
        TestAssert.True(!viewModel.ShowActivationControls && !viewModel.CanActivate,
            "Local access still exposed the key activation path");
        TestAssert.Equal("Доступные функции", viewModel.Subscription,
            "Local access advertised capabilities missing from production composition");
        TestAssert.True(
            !DeveloperFullAccessPolicy.Features.Contains("stream", StringComparer.Ordinal) &&
            !DeveloperFullAccessPolicy.Features.Contains("stream_chat", StringComparer.Ordinal),
            "Local access granted unavailable streaming capabilities");
        var accepted = viewModel.ActivateAsync("unused", CancellationToken.None)
            .GetAwaiter().GetResult();
        TestAssert.True(!accepted && !activationCalled,
            "Local access requested or activated a key");
        foreach (var rawFeature in DeveloperFullAccessPolicy.Features)
        {
            TestAssert.True(!viewModel.FeatureSummary.Contains(rawFeature, StringComparison.Ordinal),
                $"Owner-facing feature copy exposed raw id: {rawFeature}");
        }
        TestAssert.True(
            !viewModel.HeaderSubtitle.Contains("test", StringComparison.OrdinalIgnoreCase) &&
            !viewModel.HeaderSubtitle.Contains("developer", StringComparison.OrdinalIgnoreCase),
            "Owner-facing copy exposed build provenance");

        var screen = new LicenseScreen { ViewModel = viewModel };
        screen.Measure(new Size(1000, 800));
        screen.Arrange(new Rect(0, 0, 1000, 800));
        screen.UpdateLayout();
        var banner = screen.FindName("ActivationBanner") as FrameworkElement;
        var settings = screen.FindName("ActivationSettingsSection") as FrameworkElement;
        TestAssert.True(
            banner?.Visibility == Visibility.Collapsed &&
            settings?.Visibility == Visibility.Collapsed,
            "Local access still rendered the activation prompt or key controls");
    }
}
