from abc import ABC, abstractmethod

from ex0 import Creature
from ex1 import HealCapability, TransformCapability

from .exceptions import InvalidStrategyError


class BattleStrategy(ABC):
    name: str = "strategy"

    @abstractmethod
    def is_valid(self, creature: Creature) -> bool:
        """Return True if the Creature is suitable for this strategy"""
        ...

    @abstractmethod
    def act(self, creature: Creature) -> list[str]:
        """Perform this strategy's actions, returning their descriptions"""
        ...

    def _reject(self, creature: Creature) -> InvalidStrategyError:
        return InvalidStrategyError(
            f"Invalid Creature '{creature.name}' for this "
            f"{self.name} strategy"
        )


class NormalStrategy(BattleStrategy):
    name = "normal"

    def is_valid(self, creature: Creature) -> bool:
        return True

    def act(self, creature: Creature) -> list[str]:
        if not self.is_valid(creature):
            raise self._reject(creature)
        return [creature.attack()]


class AggressiveStrategy(BattleStrategy):
    name = "aggressive"

    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, TransformCapability)

    def act(self, creature: Creature) -> list[str]:
        if not isinstance(creature, TransformCapability):
            raise self._reject(creature)
        return [creature.transform(), creature.attack(), creature.revert()]


class DefensiveStrategy(BattleStrategy):
    name = "defensive"

    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, HealCapability)

    def act(self, creature: Creature) -> list[str]:
        if not isinstance(creature, HealCapability):
            raise self._reject(creature)
        return [creature.attack(), creature.heal()]
