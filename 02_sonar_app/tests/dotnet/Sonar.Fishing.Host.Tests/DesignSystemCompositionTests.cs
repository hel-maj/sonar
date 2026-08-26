using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Threading;
using System.Windows.Controls.Primitives;
using System.Windows.Input;
using System.IO;
using System.Diagnostics;
using Sonar.Fishing.Host.AboutPage;
using Sonar.Fishing.Host.EngineHealth;
using Sonar.Fishing.Host.FishingPage;
using Sonar.Fishing.Host.LicensePage;
using Sonar.Fishing.Host.InventoryPage;
using Sonar.Fishing.Host.Overview;
using Sonar.Fishing.Host.SettingsPage;
using Sonar.Fishing.Host.SettingsPersistence;
using Sonar.Fishing.Host.Shell;
using Sonar.Fishing.Host.StatisticsPage;
using Sonar.Fishing.Host.StreamingPage;
using Sonar.Fishing.Host.TelegramPage;
using Sonar.UI.Wpf.Controls;
using FishingPageControl = Sonar.Fishing.Host.FishingPage.FishingPage;

namespace Sonar.Fishing.Host.Tests;

internal static class DesignSystemCompositionTests
{
    public static IReadOnlyList<TestCase> Create() =>
    [
        new("common_app_shell_switches_compact_without_resolution_assumption", AppShellIsResponsive),
        new("navigation_footer_never_overlaps_navigation_or_page_content", FooterDoesNotOverlapContent),
        new("overview_fits_compact_viewport_without_page_scroll", OverviewFitsCompactViewport),
        new("embedded_fishing_brand_has_no_loose_runtime_asset", BrandIsEmbedded),
        new("all_nine_product_pages_are_composed_from_common_patterns", AllPagesAreComposed),
        new("page_content_uses_one_shared_header_gap", PageContentUsesOneSharedHeaderGap),
        new("settings_page_persists_one_complete_next_revision", SettingsSaveIsAtomic),
        new("rapid_product_settings_toggles_preserve_final_intent_without_banner_spam", RapidSettingsTogglesRemainResponsive),
        new("repeated_product_navigation_and_focus_never_resolve_unset_value", RepeatedNavigationAndFocusRemainStable),
        new("settings_combo_projects_record_labels_in_selection_and_dropdown", SettingsComboProjectsRecordLabels),
        new("product_text_inputs_use_common_keyed_templates", ProductTextInputsUseCommonTemplates),
        new("settings_threshold_sliders_use_common_template_without_geometry_change", SettingsSlidersUseCommonTemplate),
        new("fish_selection_uses_common_nested_scroll_gutter", FishSelectionUsesCommonScrollGutter),
        new("telegram_page_persists_secret_and_policy_without_engine_boundary", TelegramSaveIsHostOwned),
        new("telegram_credentials_use_supported_icons_and_visible_editors", TelegramCredentialEditorsAreVisible),
        new("statistics_table_stacks_before_columns_become_unreadable", StatisticsTableStaysReadable),
        new("streaming_page_preserves_product_command_and_setting_union", StreamingPagePreservesUnion),
    ];

    private static void AppShellIsResponsive()
    {
        var shell = new FishingHostShell();
        Arrange(shell, new Size(640, 700));
        var appShell = TestAssert.IsType<AppShell>(
            shell.FindName("ApplicationShell"),
            "Common AppShell is missing");
        TestAssert.True(appShell.IsCompact, "AppShell did not enter compact mode from available width");

        Arrange(shell, new Size(1_280, 760));
        TestAssert.True(!appShell.IsCompact, "AppShell stayed compact at expanded available width");
    }

    private static void FooterDoesNotOverlapContent()
    {
        var shell = new FishingHostShell();
        foreach (var size in new[] { new Size(640, 720), new Size(1_280, 800) })
        {
            Arrange(shell, size);
            var pageHost = TestAssert.IsType<ContentControl>(
                shell.FindName("PageHost"),
                "Page host is missing");
            var footer = TestAssert.IsType<StackPanel>(
                shell.FindName("FooterPanel"),
                "Navigation footer is missing");
            var navigation = TestAssert.IsType<StackPanel>(
                shell.FindName("NavigationPanel"),
                "Navigation panel is missing");
            var pageBounds = BoundsWithin(shell, pageHost);
            var footerBounds = BoundsWithin(shell, footer);
            var navigationBounds = BoundsWithin(shell, navigation);
            TestAssert.True(
                footerBounds.Right <= pageBounds.Left + 0.5,
                $"Navigation footer overlaps page content at {size.Width}x{size.Height}");
            TestAssert.True(
                navigationBounds.Bottom <= footerBounds.Top + 0.5,
                $"Navigation footer overlaps navigation at {size.Width}x{size.Height}");
        }
    }

    private static Rect BoundsWithin(Visual ancestor, FrameworkElement element) =>
        element.TransformToAncestor(ancestor).TransformBounds(
            new Rect(new Point(0, 0), element.RenderSize));

    private static void OverviewFitsCompactViewport()
    {
        var shell = new FishingHostShell
        {
            ViewModel = UiGalleryRenderer.CreateGalleryViewModel(),
        };
        shell.ViewModel.ShowOverviewCommand.Execute(null);
        Arrange(shell, new Size(640, 720));
        var overview = WpfTestVisualTree.FindDescendant<OverviewScreen>(
            shell,
            "Overview page is missing");
        var scroller = TestAssert.IsType<ScrollViewer>(
            overview.FindName("OverviewPageScrollViewer"),
            "Overview page scroll viewer is missing");

        TestAssert.True(
            scroller.ScrollableHeight <= 0.5,
            $"Overview requires {scroller.ScrollableHeight:F1} DIP of avoidable compact scrolling");
    }

    private static void BrandIsEmbedded()
    {
        var uri = new Uri(
            "pack://application:,,,/Sonar.Fishing.Host;component/Assets/sonar_logo.png",
            UriKind.Absolute);
        using var stream = Application.GetResourceStream(uri)?.Stream;
        TestAssert.True(stream is { Length: > 0 }, "Embedded Fishing logo resource is missing");
        TestAssert.True(
            !File.Exists(Path.Combine(AppContext.BaseDirectory, "Assets", "sonar_logo.png")),
            "Fishing logo leaked into output as a loose runtime asset");
    }

    private static void AllPagesAreComposed()
    {
        var shell = new FishingHostShell();
        Arrange(shell, new Size(1_180, 760));
        AssertPage<LicenseScreen>(shell, () => shell.ViewModel.ShowLicenseCommand.Execute(null));
        AssertPage<OverviewScreen>(shell, () => shell.ViewModel.ShowOverviewCommand.Execute(null));
        AssertPage<FishingPageControl>(shell, () => shell.ViewModel.ShowFishingCommand.Execute(null));
        AssertPage<InventoryScreen>(shell, () => shell.ViewModel.ShowInventoryCommand.Execute(null));
        AssertPage<SettingsScreen>(shell, () => shell.ViewModel.ShowSettingsCommand.Execute(null));
        AssertPage<StatisticsScreen>(shell, () => shell.ViewModel.ShowStatisticsCommand.Execute(null));
        AssertPage<StreamingScreen>(shell, () => shell.ViewModel.ShowStreamingCommand.Execute(null));
        AssertPage<TelegramScreen>(shell, () => shell.ViewModel.ShowTelegramCommand.Execute(null));
        AssertPage<AboutScreen>(shell, () => shell.ViewModel.ShowAboutCommand.Execute(null));
    }

    private static void PageContentUsesOneSharedHeaderGap()
    {
        var shell = new FishingHostShell
        {
            ViewModel = UiGalleryRenderer.CreateGalleryViewModel(),
        };
        var pages = new (string Title, Action Navigate)[]
        {
            ("Проверка приложения", () => shell.ViewModel.ShowEngineHealthCommand.Execute(null)),
            ("Лицензия", () => shell.ViewModel.ShowLicenseCommand.Execute(null)),
            ("Обзор", () => shell.ViewModel.ShowOverviewCommand.Execute(null)),
            ("Рыбалка", () => shell.ViewModel.ShowFishingCommand.Execute(null)),
            ("Инвентарь", () => shell.ViewModel.ShowInventoryCommand.Execute(null)),
            ("Настройки", () => shell.ViewModel.ShowSettingsCommand.Execute(null)),
            ("Статистика", () => shell.ViewModel.ShowStatisticsCommand.Execute(null)),
            ("Стрим", () => shell.ViewModel.ShowStreamingCommand.Execute(null)),
            ("Telegram", () => shell.ViewModel.ShowTelegramCommand.Execute(null)),
            ("О программе", () => shell.ViewModel.ShowAboutCommand.Execute(null)),
        };

        foreach (var (title, navigate) in pages)
        {
            navigate();
            Arrange(shell, new Size(1_280, 800));
            var pageHost = TestAssert.IsType<ContentControl>(
                shell.FindName("PageHost"),
                "Page host is missing");
            var header = WpfTestVisualTree.FindDescendants<PageHeader>(pageHost)
                .Single(item => string.Equals(item.Title, title, StringComparison.Ordinal));
            var stack = TestAssert.IsType<StackPanel>(
                VisualTreeHelper.GetParent(header),
                $"{title} page header is not placed in the page content stack");
            var headerIndex = stack.Children.IndexOf(header);
            var firstContent = stack.Children
                .OfType<FrameworkElement>()
                .Skip(headerIndex + 1)
                .FirstOrDefault(item => item.Visibility == Visibility.Visible)
                ?? throw new InvalidOperationException($"{title} page content is missing");
            var headerBounds = BoundsWithin(stack, header);
            var contentBounds = BoundsWithin(stack, firstContent);
            var actualGap = contentBounds.Top - headerBounds.Bottom;

            TestAssert.Equal(
                0d,
                firstContent.Margin.Top,
                $"{title} page adds a second top margin after PageHeader");
            TestAssert.True(
                Math.Abs(actualGap - header.Margin.Bottom) <= 0.5,
                $"{title} page header gap is {actualGap:F1} DIP instead of the shared " +
                $"{header.Margin.Bottom:F1} DIP");
        }
    }

    private static void SettingsSaveIsAtomic()
    {
        FishingRuntimeSettings? persisted = null;
        var viewModel = new FishingSettingsPageViewModel(
            FishingRuntimeSettings.CreateDefault(revision: 7),
            settings => persisted = settings);
        viewModel.AutoMeal = false;
        viewModel.StartStopShortcut = HotkeyGesture.ParseInvariant("F8");
        viewModel.SaveCommand.Execute(null);

        TestAssert.True(persisted is not null, "Settings save callback was not invoked");
        TestAssert.Equal<ulong>(8, persisted!.Revision, "Settings revision did not advance once");
        TestAssert.True(!persisted.Behavior.AutoMeal, "Behavior edit was not persisted");
        TestAssert.Equal("F8", persisted.Hotkeys.StartStop, "Hotkey edit was not normalized");
        TestAssert.True(!viewModel.IsDirty, "Saved settings remained dirty");
        TestAssert.Equal(string.Empty, viewModel.SaveStatus, "Successful settings save exposed a flash banner");
    }

    private static void RapidSettingsTogglesRemainResponsive()
    {
        FishingRuntimeSettings? persisted = null;
        var viewModel = new FishingSettingsPageViewModel(
            FishingRuntimeSettings.CreateDefault(revision: 17),
            settings => persisted = settings);
        var screen = new SettingsScreen { ViewModel = viewModel };
        Arrange(screen, new Size(1_280, 800));
        var toggle = WpfTestVisualTree.FindDescendants<ToggleSwitch>(screen).First();
        var saveStatusChanges = 0;
        viewModel.PropertyChanged += (_, args) =>
        {
            if (args.PropertyName == nameof(FishingSettingsPageViewModel.SaveStatus))
            {
                saveStatusChanges++;
            }
        };

        const int toggleCount = 501;
        var elapsed = Stopwatch.StartNew();
        for (var index = 0; index < toggleCount; index++)
        {
            toggle.SetCurrentValue(
                ToggleButton.IsCheckedProperty,
                !(toggle.IsChecked ?? false));
        }
        Dispatcher.CurrentDispatcher.Invoke(
            () => { },
            DispatcherPriority.Background);
        elapsed.Stop();

        TestAssert.True(
            elapsed.Elapsed < TimeSpan.FromSeconds(2),
            $"Rapid product toggles blocked the STA dispatcher for {elapsed.Elapsed}");
        TestAssert.True(!viewModel.AutoMeal, "Rapid product toggles lost the final intent");
        TestAssert.True(viewModel.SaveCommand.CanExecute(null), "Final toggle state was not saveable");
        viewModel.SaveCommand.Execute(null);
        TestAssert.True(persisted is not null, "Rapid product settings were not persisted");
        TestAssert.True(!persisted!.Behavior.AutoMeal, "Persisted settings lost the final toggle intent");
        TestAssert.Equal<ulong>(18, persisted.Revision, "Rapid toggles advanced more than one saved revision");
        TestAssert.Equal(0, saveStatusChanges, "Rapid toggles emitted transient save-banner state");
        TestAssert.Equal(string.Empty, viewModel.SaveStatus, "Rapid toggle save exposed a banner");
    }

    private static void RepeatedNavigationAndFocusRemainStable()
    {
        var shell = new FishingHostShell
        {
            ViewModel = FishingHostShellViewModel.CreatePreview(),
        };
        Arrange(shell, new Size(1_280, 800));
        var routes = new Action[]
        {
            () => shell.ViewModel.ShowOverviewCommand.Execute(null),
            () => shell.ViewModel.ShowFishingCommand.Execute(null),
            () => shell.ViewModel.ShowInventoryCommand.Execute(null),
            () => shell.ViewModel.ShowSettingsCommand.Execute(null),
            () => shell.ViewModel.ShowStatisticsCommand.Execute(null),
            () => shell.ViewModel.ShowStreamingCommand.Execute(null),
            () => shell.ViewModel.ShowTelegramCommand.Execute(null),
            () => shell.ViewModel.ShowAboutCommand.Execute(null),
            () => shell.ViewModel.ShowLicenseCommand.Execute(null),
        };
        var observedControls = 0;
        var traversalAttempts = 0;
        for (var pass = 0; pass < 3; pass++)
        {
            foreach (var route in routes)
            {
                route();
                Arrange(shell, new Size(1_280, 800));
                Dispatcher.CurrentDispatcher.Invoke(
                    () => { },
                    DispatcherPriority.Background);
                var pageHost = TestAssert.IsType<ContentControl>(
                    shell.FindName("PageHost"),
                    "Page host is missing during focus stability pass");
                foreach (var control in WpfTestVisualTree.FindDescendants<Control>(pageHost)
                             .Where(item => item.Focusable && item.IsEnabled &&
                                 item.Visibility == Visibility.Visible)
                             .Take(8))
                {
                    control.ApplyTemplate();
                    FocusManager.SetFocusedElement(shell, control);
                    _ = control.MoveFocus(new TraversalRequest(
                        FocusNavigationDirection.Next));
                    traversalAttempts++;
                    var focusVisual = control.GetValue(Control.FocusVisualStyleProperty);
                    TestAssert.True(
                        !ReferenceEquals(focusVisual, DependencyProperty.UnsetValue),
                        $"{control.GetType().Name} resolved FocusVisualStyle to UnsetValue");
                    observedControls++;
                }
            }
        }
        TestAssert.True(observedControls >= 24, "Product focus pass did not exercise enough controls");
        TestAssert.True(
            traversalAttempts == observedControls,
            "Product keyboard traversal did not cover every focused control");
    }

    private static void SettingsComboProjectsRecordLabels()
    {
        var shell = new FishingHostShell
        {
            ViewModel = FishingHostShellViewModel.CreatePreview(),
        };
        shell.ViewModel.ShowSettingsCommand.Execute(null);
        Arrange(shell, new Size(1_280, 800));
        var screen = WpfTestVisualTree.FindDescendant<SettingsScreen>(
            shell,
            "Settings page is missing");
        var selector = TestAssert.IsType<NonScrollingComboBox>(
            screen.FindName("FoodDepletedActionSelector"),
            "Food depleted action selector is missing");
        selector.ApplyTemplate();
        Arrange(shell, new Size(1_280, 800));

        var visibleText = WpfTestVisualTree.FindDescendants<TextBlock>(selector)
            .Select(item => item.Text)
            .Where(item => !string.IsNullOrEmpty(item))
            .ToArray();
        TestAssert.True(
            visibleText.Contains("Продолжить рыбалку", StringComparer.Ordinal),
            "Selected settings option label was not rendered");
        TestAssert.True(
            visibleText.All(item => !item.Contains("FishingSettingsOption", StringComparison.Ordinal)),
            "Selected settings option leaked its raw record representation");

        var generator = (IItemContainerGenerator)selector.ItemContainerGenerator;
        using var generation = generator.StartAt(
            new GeneratorPosition(-1, 0),
            GeneratorDirection.Forward,
            allowStartAtRealizedItem: true);
        var dropDownItem = TestAssert.IsType<ComboBoxItem>(
            generator.GenerateNext(out _),
            "Settings dropdown item was not generated");
        generator.PrepareItemContainer(dropDownItem);
        var dropDownHost = new Grid();
        dropDownHost.Children.Add(dropDownItem);
        Arrange(dropDownHost, new Size(360, 64));

        var dropDownText = WpfTestVisualTree.FindDescendants<TextBlock>(dropDownItem)
            .Select(item => item.Text)
            .Where(item => !string.IsNullOrEmpty(item))
            .ToArray();
        TestAssert.True(
            dropDownText.Contains("Продолжить рыбалку", StringComparer.Ordinal),
            "Settings dropdown item did not render its DisplayMemberPath label");
        TestAssert.True(
            dropDownText.All(item =>
                !item.Contains("FishingSettingsOption", StringComparison.Ordinal)),
            "Settings dropdown item leaked its raw record representation");
    }

    private static void ProductTextInputsUseCommonTemplates()
    {
        var textBoxStyle = TestAssert.IsType<Style>(
            Application.Current.TryFindResource("Sonar.Input.TextBox"),
            "Common TextBox style is missing");
        var passwordBoxStyle = TestAssert.IsType<Style>(
            Application.Current.TryFindResource("Sonar.Input.PasswordBox"),
            "Common PasswordBox style is missing");
        _ = TestAssert.IsType<Style>(
            Application.Current.TryFindResource(typeof(CheckBox)),
            "Common implicit CheckBox style is missing");

        var shell = new FishingHostShell
        {
            ViewModel = FishingHostShellViewModel.CreatePreview(),
        };
        Arrange(shell, new Size(1_280, 800));
        var license = WpfTestVisualTree.FindDescendant<LicenseScreen>(
            shell,
            "License page is missing");
        var licenseKey = TestAssert.IsType<PasswordBox>(
            license.FindName("LicenseKeyEditor"),
            "License key editor is missing");
        TestAssert.True(
            ReferenceEquals(passwordBoxStyle, licenseKey.Style),
            "License key editor uses the system PasswordBox template");

        shell.ViewModel.ShowTelegramCommand.Execute(null);
        Arrange(shell, new Size(1_280, 800));
        var telegram = WpfTestVisualTree.FindDescendant<TelegramScreen>(
            shell,
            "Telegram page is missing");
        foreach (var name in new[] { "AdminIdsEditor", "InventoryThresholdEditor" })
        {
            var editor = TestAssert.IsType<TextBox>(
                telegram.FindName(name),
                $"Telegram editor {name} is missing");
            TestAssert.True(
                ReferenceEquals(textBoxStyle, editor.Style),
                $"Telegram editor {name} uses the system TextBox template");
        }
        var token = TestAssert.IsType<PasswordBox>(
            telegram.FindName("BotTokenEditor"),
            "Telegram token editor is missing");
        TestAssert.True(
            ReferenceEquals(passwordBoxStyle, token.Style),
            "Telegram token editor uses the system PasswordBox template");
    }

    private static void SettingsSlidersUseCommonTemplate()
    {
        var commonStyle = TestAssert.IsType<Style>(
            Application.Current.TryFindResource("Sonar.Input.Slider"),
            "Common Slider style is missing");
        var shell = new FishingHostShell
        {
            ViewModel = FishingHostShellViewModel.CreatePreview(),
        };
        shell.ViewModel.ShowSettingsCommand.Execute(null);
        Arrange(shell, new Size(1_280, 800));
        var screen = WpfTestVisualTree.FindDescendant<SettingsScreen>(
            shell,
            "Settings page is missing");

        Slider? interactionSlider = null;
        foreach (var name in new[]
                 {
                     "FoodThresholdSlider",
                     "WaterThresholdSlider",
                     "HealthThresholdSlider",
                 })
        {
            var slider = TestAssert.IsType<Slider>(
                screen.FindName(name),
                $"Settings slider {name} is missing");
            TestAssert.True(
                ReferenceEquals(commonStyle, slider.Style),
                $"Settings slider {name} uses a system style");
            TestAssert.True(
                ReferenceEquals(
                    slider.ReadLocalValue(Control.TemplateProperty),
                    DependencyProperty.UnsetValue),
                $"Settings slider {name} has a product-local template");
            TestAssert.Equal(1d, slider.Minimum, $"Settings slider {name} minimum changed");
            TestAssert.Equal(90d, slider.Maximum, $"Settings slider {name} maximum changed");
            TestAssert.Equal(1d, slider.TickFrequency, $"Settings slider {name} tick changed");
            TestAssert.Equal(160d, slider.Width, $"Settings slider {name} usable width changed");
            slider.ApplyTemplate();
            _ = TestAssert.IsType<Track>(
                slider.Template.FindName("PART_Track", slider),
                $"Common Slider track is missing for {name}");
            _ = WpfTestVisualTree.FindDescendant<Thumb>(
                slider,
                $"Common Slider thumb is missing for {name}");
            interactionSlider ??= slider;
        }

        TestAssert.True(interactionSlider is not null, "Settings interaction slider is missing");
        interactionSlider!.Value = 45;
        var interactionTrack = TestAssert.IsType<Track>(
            interactionSlider.Template.FindName("PART_Track", interactionSlider),
            "Common Slider interaction track is missing");
        var increase = interactionTrack.IncreaseRepeatButton;
        TestAssert.True(
            ReferenceEquals(increase.CommandTarget, interactionSlider),
            "Common Slider command is not routed to the Fishing control");
        var increaseCommand = TestAssert.IsType<RoutedCommand>(
            increase.Command,
            "Common Slider increase command is missing");
        TestAssert.True(
            increaseCommand.CanExecute(increase.CommandParameter, increase.CommandTarget),
            "Common Slider increase command is unavailable in Fishing settings");
        increaseCommand.Execute(increase.CommandParameter, increase.CommandTarget);
        TestAssert.Equal(50d, interactionSlider.Value, "Fishing threshold did not apply LargeChange");
    }

    private static void FishSelectionUsesCommonScrollGutter()
    {
        var commonStyle = TestAssert.IsType<Style>(
            Application.Current.TryFindResource("Sonar.ContentScrollViewer"),
            "Common nested content scroller style is missing");
        var shell = new FishingHostShell
        {
            ViewModel = FishingHostShellViewModel.CreatePreview(),
        };
        shell.ViewModel.ShowSettingsCommand.Execute(null);
        Arrange(shell, new Size(1_280, 800));
        var screen = WpfTestVisualTree.FindDescendant<SettingsScreen>(
            shell,
            "Settings page is missing");
        var scroller = TestAssert.IsType<ScrollViewer>(
            screen.FindName("FishSelectionScrollViewer"),
            "Fish selection scroller is missing");
        scroller.ApplyTemplate();
        Arrange(shell, new Size(1_280, 800));

        TestAssert.True(
            ReferenceEquals(commonStyle, scroller.Style),
            "Fish selection scroller does not use the Common content style");
        TestAssert.Equal(12d, scroller.Padding.Right, "Fish selection right gutter changed");
        var content = TestAssert.IsType<FrameworkElement>(
            scroller.Content,
            "Fish selection content is missing");
        var verticalBar = WpfTestVisualTree.FindDescendants<ScrollBar>(scroller)
            .Single(bar => bar.Orientation == Orientation.Vertical);
        var contentBounds = BoundsWithin(scroller, content);
        var barBounds = BoundsWithin(scroller, verticalBar);
        TestAssert.True(
            barBounds.Left - contentBounds.Right >= 11.5,
            "Fish selection controls crowd the nested scrollbar");
    }

    private static void TelegramSaveIsHostOwned()
    {
        TelegramSettingsSaveResult? persisted = null;
        var settings = new TelegramHostSettings(
            false,
            [42],
            1.0,
            TelegramHostSettings.Default.Notifications);
        var viewModel = new TelegramSettingsPageViewModel(
            settings,
            "fake-token",
            featureAllowed: true,
            TelegramAvailability.Available("fake-token", [42]),
            result => persisted = result);
        viewModel.NotifyFocusLost = true;
        viewModel.SaveCommand.Execute(null);

        TestAssert.True(persisted is not null, "Telegram save callback was not invoked");
        TestAssert.Equal("fake-token", persisted!.BotToken, "Telegram token changed during Host save");
        TestAssert.True(persisted.Settings.Notifications.FocusLost, "Telegram policy edit was lost");
        TestAssert.True(!viewModel.IsDirty, "Saved Telegram settings remained dirty");
        TestAssert.Equal(
            string.Empty,
            viewModel.InteractionMessage,
            "Successful Telegram save exposed a flash banner");
    }

    private static void TelegramCredentialEditorsAreVisible()
    {
        var shell = new FishingHostShell
        {
            ViewModel = FishingHostShellViewModel.CreatePreview(),
        };
        shell.ViewModel.ShowTelegramCommand.Execute(null);
        Arrange(shell, new Size(640, 720));
        var screen = WpfTestVisualTree.FindDescendant<TelegramScreen>(
            shell,
            "Telegram page is missing");
        var tokenEditor = TestAssert.IsType<PasswordBox>(
            screen.FindName("BotTokenEditor"),
            "Telegram token editor is missing");
        var adminEditor = TestAssert.IsType<TextBox>(
            screen.FindName("AdminIdsEditor"),
            "Telegram administrator editor is missing");
        var tokenIcon = TestAssert.IsType<IconPresenter>(
            screen.FindName("BotTokenIcon"),
            "Telegram token icon is missing");
        var adminIcon = TestAssert.IsType<IconPresenter>(
            screen.FindName("AdminIdsIcon"),
            "Telegram administrator icon is missing");
        var interactionBanner = TestAssert.IsType<NotificationBanner>(
            screen.FindName("TelegramInteractionBanner"),
            "Telegram interaction banner is missing");

        TestAssert.True(tokenEditor.ActualWidth >= 180, "Telegram token editor collapsed to a tofu-sized glyph");
        TestAssert.True(adminEditor.ActualWidth >= 180, "Telegram administrator editor collapsed to a tofu-sized glyph");
        TestAssert.Equal("●", tokenIcon.Glyph, "Telegram token icon changed to an unsupported glyph");
        TestAssert.Equal("#", adminIcon.Glyph, "Telegram administrator icon changed to an unsupported glyph");
        TestAssert.Equal(
            Visibility.Collapsed,
            interactionBanner.Visibility,
            "Telegram page exposed a blank interaction banner");
    }

    private static void StatisticsTableStaysReadable()
    {
        var shell = new FishingHostShell
        {
            ViewModel = FishingHostShellViewModel.CreatePreview(),
        };
        shell.ViewModel.ShowStatisticsCommand.Execute(null);
        Arrange(shell, new Size(1_280, 800));
        var screen = WpfTestVisualTree.FindDescendant<StatisticsScreen>(
            shell,
            "Statistics page is missing");
        var composition = TestAssert.IsType<MasterDetail>(
            screen.FindName("StatisticsComposition"),
            "Statistics master/detail composition is missing");
        var table = TestAssert.IsType<DataGrid>(
            screen.FindName("FishStatisticsTable"),
            "Statistics fish table is missing");

        TestAssert.True(
            composition.IsStacked,
            "Statistics table was compressed beside the chart below the expanded-content breakpoint");
        TestAssert.True(
            table.Columns.All(column => column.MinWidth >= 96),
            "Statistics table column lost its readable minimum width");
        TestAssert.True(
            table.Columns[^1].MinWidth >= 176,
            "Statistics income range column can clip its product value");
    }

    private static void StreamingPagePreservesUnion()
    {
        var shell = new FishingHostShell
        {
            ViewModel = FishingHostShellViewModel.CreatePreview(),
        };
        shell.ViewModel.ShowStreamingCommand.Execute(null);
        Arrange(shell, new Size(1_280, 800));
        var screen = WpfTestVisualTree.FindDescendant<StreamingScreen>(
            shell,
            "Streaming page is missing");

        _ = TestAssert.IsType<ActionButton>(screen.FindName("StreamStartButton"), "Stream start action is missing");
        _ = TestAssert.IsType<ActionButton>(screen.FindName("StreamStopButton"), "Stream stop action is missing");
        _ = TestAssert.IsType<ActionButton>(screen.FindName("StreamChatModeButton"), "Stream chat action is missing");
        _ = TestAssert.IsType<NonScrollingComboBox>(screen.FindName("StreamQualitySelector"), "Stream quality selector is missing");
        _ = TestAssert.IsType<ToggleSwitch>(screen.FindName("StreamChatZoomToggle"), "Stream chat zoom toggle is missing");
        _ = TestAssert.IsType<ToggleSwitch>(screen.FindName("StreamLowFpsToggle"), "Stream 10fps toggle is missing");
        TestAssert.Equal(3, screen.ViewModel.QualityOptions.Count, "Stream quality union changed");
    }

    private static void AssertPage<T>(FishingHostShell shell, Action navigate)
        where T : DependencyObject
    {
        navigate();
        Arrange(shell, new Size(1_180, 760));
        _ = WpfTestVisualTree.FindDescendant<T>(shell, $"{typeof(T).Name} was not composed");
    }

    private static void Arrange(FrameworkElement element, Size size)
    {
        element.Measure(size);
        element.Arrange(new Rect(new Point(0, 0), size));
        element.Dispatcher.Invoke(() => { }, DispatcherPriority.DataBind);
        element.UpdateLayout();
    }
}
