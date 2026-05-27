# lab_serialization

Serializes and deserializes a collection of geometric figures (circles, quadrangles) to/from JSON using [nlohmann/json](https://github.com/nlohmann/json). Figures are generated with random coordinates and colors, written to `data.json`, then reconstructed and equality-asserted.

## Tech Stack

C++17, nlohmann/json (header-only, bundled)

## Quick Start

```bash
# Build and run
make build

# Debug build
make debug

# Clean
make clean
```

> Requires `g++` with C++17 support. The nlohmann/json header must be present at `include/single_include/nlohmann/json.hpp`.

## Output

Writes serialized figures to `data.json`. Prints figure info before and after deserialization, then runs an equality assertion.
