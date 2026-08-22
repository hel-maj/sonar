namespace Sonar.Fishing.Host.HostDiagnostics;

internal enum ProductDiagnosticLevel
{
    Information,
    Warning,
    Error,
}

internal sealed record ProductDiagnosticEntry(
    DateTimeOffset OccurredAt,
    ProductDiagnosticLevel Level,
    string EventId,
    string Message);
