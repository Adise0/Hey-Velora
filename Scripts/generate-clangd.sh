#!/usr/bin/env bash
# Regenerates compile_commands.json for clangd.
# Run from Git Bash after adding classes, modules or plugins.
# Set UE_ROOT if the engine is not in the default location.
set -euo pipefail

UE_ROOT="${UE_ROOT:-C:/Program Files/Epic Games/UE_5.7}"

# cygpath -m gives D:/... paths, which both bash and Unreal accept
PROJECT_DIR="$(cygpath -m "$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)")"
BUILD_BAT="$(cygpath -u "$UE_ROOT")/Engine/Build/BatchFiles/Build.bat"

if [[ ! -f "$BUILD_BAT" ]]; then
    echo "Build.bat not found at $BUILD_BAT. Set UE_ROOT to your engine folder." >&2
    exit 1
fi

"$BUILD_BAT" -Mode=GenerateClangDatabase HeyVeloraEditor Win64 Development \
    "-Project=$PROJECT_DIR/HeyVelora.uproject" \
    "-OutputDir=$PROJECT_DIR" \
    -WaitMutex

echo "Done. In VS Code, run 'clangd: Restart language server' if errors remain."
