using Sonar.Fishing.Host.LicensePage;
using Sonar.Fishing.Host.SettingsPersistence;

namespace Sonar.Fishing.Host.Tests;

internal static class LicensePageTests
{
    internal static IEnumerable<TestCase> Create()
    {
        yield return new TestCase(
            "unvalidated_license_never_exposes_migration_group_copy",
            UnvalidatedLicenseNeverExposesMigrationGroupCopy);
    }

    private static void UnvalidatedLicenseNeverExposesMigrationGroupCopy()
    {
        var viewModel = new LicensePageViewModel(LicenseHostSettings.Default);

        TestAssert.True(!viewModel.HasValidatedLicense, "Default license became validated");
        TestAssert.Equal("—", viewModel.Subscription, "Migration group leaked into user-facing subscription");
        TestAssert.Equal("—", viewModel.ExpiresAt, "Missing expiry did not stay neutral");
    }
}
