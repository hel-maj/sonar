"""License validation and activation support."""

from sonar.license.client import LicenseStatus
from sonar.license.context import LicenseContext
from sonar.license.manager import LicenseManager

__all__ = ["LicenseContext", "LicenseManager", "LicenseStatus"]
