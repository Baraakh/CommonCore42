from abc import ABC, abstractmethod
from typing import Optional


class HealCapability(ABC):
    @abstractmethod
    def heal(self, target: Optional["HealCapability"] = None) -> str:
        """Return a string describing the healing action"""
        ...


class TransformCapability(ABC):
    _transformed: bool

    @abstractmethod
    def transform(self) -> str:
        """Return a string describing the transformation"""
        ...

    @abstractmethod
    def revert(self) -> str:
        """Return a string describing reverting to normal form"""
        ...
