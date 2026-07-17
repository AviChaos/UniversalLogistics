# Changelog

All notable changes to **Universal Logistics** will be documented in this file.

This project follows **Semantic Versioning** during active development.

---

# v0.2.0 — Sprint 2 Complete (Current)

Release Date: *2026*

## Added

### Core Mod Infrastructure

- Universal Logistics Game Feature Plugin
- Root Game World registration
- Custom plugin configuration
- Asset scanning configuration
- Custom schematic registration
- Custom recipe registration
- Custom building descriptor
- First production buildable

### First Universal Logistics Splitter

- Added the first fully functional Universal Logistics Splitter.
- Implemented as an independent buildable.
- Uses vanilla splitter behaviour while remaining completely independent from FactoryGame assets.

### Gameplay Integration

Verified compatibility with:

- Conveyor Belts
- Conveyor Lifts
- Build Gun
- Build Menu
- Dismantle System
- Mass Dismantle
- Blueprint Designer
- Save/Load System
- Customizer (Paint)
- Conveyor Throughput

### Development

- Successfully migrated development to `ULWorkspace_v2`.
- Rebuilt the complete project using Visual Studio 2022.
- Established the Universal Logistics GitHub repository.
- Introduced sprint-based release workflow.
- Added development documentation.

---

## Changed

- Updated project version from **v0.1.0** to **v0.2.0**.
- Refined project philosophy to focus on orientation-based logistics expansion.
- Improved repository structure and documentation.

---

## Technical Discoveries

- Existing Coffee Stain splitter logic can be reused safely through inheritance.
- Functional buildables require the complete Descriptor → Recipe → Schematic → Buildable chain.
- `FGBuildingDescriptor` is required for buildable registration.
- Buildable holograms can be replaced independently of gameplay behaviour.
- Conveyor attachment logic is inherited from the parent splitter implementation.
- Alpakit remains the recommended deployment workflow.

---

## Sprint Status

| Sprint | Status |
|---------|--------|
| Sprint 0 | ✅ Complete |
| Sprint 1 | ✅ Complete |
| Sprint 2 | ✅ Complete |
| Sprint 3 | 🚧 In Progress |

---

## Upcoming (Sprint 3)

- Create additional splitter orientations.
- Develop the orientation framework.
- Improve build icons and naming.
- Continue investigating hologram customization.
- Prepare the first Universal Logistics merger.

---

# v0.1.0 — Sprint 0

## Added

- Created the Universal Logistics mod using Alpakit.
- Configured the C++ and Blueprint project structure.
- Added Git version control.
- Added project documentation.
- Established repository structure.
- Defined project philosophy.
- Created long-term development roadmap.

## Infrastructure

- Unreal Engine 5.6.1 (Coffee Stain Source Build)
- Satisfactory Mod Loader (SML)
- Alpakit
- Visual Studio 2022
- Git

## Result

Sprint 0 successfully established the complete development environment used throughout the project.
