namespace Sonar.Fishing.Host.StartupGate;

public sealed class StartupAdmissionCoordinator
{
    private readonly IStartupBlockCheck startupBlockCheck;
    private readonly StartupBlockRequest request;
    private readonly StartupAdmissionViewModel viewModel;

    public StartupAdmissionCoordinator(
        IStartupBlockCheck startupBlockCheck,
        StartupBlockRequest request,
        StartupAdmissionViewModel viewModel)
    {
        this.startupBlockCheck = startupBlockCheck ??
            throw new ArgumentNullException(nameof(startupBlockCheck));
        this.request = request ?? throw new ArgumentNullException(nameof(request));
        this.viewModel = viewModel ?? throw new ArgumentNullException(nameof(viewModel));
    }

    public async Task<StartupAdmissionDecision> CheckInitialAsync(
        CancellationToken cancellationToken)
    {
        viewModel.BeginCheck();
        StartupBlockStatus status;
        try
        {
            status = await startupBlockCheck.CheckAsync(
                request,
                cancellationToken).ConfigureAwait(true);
        }
        catch (OperationCanceledException) when (cancellationToken.IsCancellationRequested)
        {
            throw;
        }
        catch (Exception)
        {
            status = StartupBlockStatus.Failure("startup_block_check_failed");
        }

        var decision = StartupAdmissionPolicy.InitialLaunch(status);
        viewModel.Apply(decision);
        return decision;
    }
}
