# SprintASM

SprintASM or SASM is the Assembly format used by Sprint. It's custom made and tries to be multiplatform.

## Instructions

### `move` instruction set
The `move` instruction set is a basic instruction allowing you to move things from a source to an origin.

#### Limitation
There is an limitation to the `move` instruction, you cannot directly set from memory to memory directly, you can however do this in two instructions by doing:
```SASM
move64 si <your address content>
move64 <your target address> si
```

#### Variants
The `move` instruction set has the following variants:
- `move8`: Moves 8 bits
- `move16`: Moves 16 bits
- `move32`: Moves 32 bits
- `move64`: Moves 64 bits