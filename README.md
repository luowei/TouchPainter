# TouchPainter

A comprehensive iOS drawing application demonstrating **Gang of Four (GoF) Design Patterns** in Objective-C. This project is the companion source code for *Pro Objective-C Design Patterns for iOS*.

## Overview

TouchPainter is an educational iOS application that allows users to draw on a canvas with various brush types and colors. The app serves as a practical demonstration of how classic design patterns can be applied to real-world iOS development.

## Features

- **Drawing Canvas**: Multi-touch drawing with customizable stroke colors and sizes
- **Multiple Canvas Types**: Switch between Paper and Cloth canvas textures
- **Scribble Management**: Save, open, and delete drawings
- **Thumbnail Gallery**: View saved drawings in a grid layout
- **Color Palette**: Choose from various stroke colors
- **Undo/Redo**: Full support for undoing and redoing drawing actions
- **Adjustable Brush Size**: Customize stroke thickness

## Design Patterns Implemented

This project demonstrates the following GoF design patterns:

### Behavioral Patterns

1. **Command Pattern** (`Classes/Command/`)
   - `Command.h/m` - Base command class
   - `SaveScribbleCommand` - Save drawing command
   - `OpenScribbleCommand` - Open drawing command
   - `DeleteScribbleCommand` - Delete drawing command
   - `SetStrokeColorCommand` - Change stroke color
   - `SetStrokeSizeCommand` - Change stroke size

2. **Visitor Pattern** (`Classes/Visitor/`)
   - `MarkVisitor.h` - Visitor protocol
   - `MarkRenderer` - Renders marks using the visitor pattern

3. **Iterator Pattern** (`Classes/Iterator/`)
   - `MarkEnumerator` - Custom iterator for traversing mark hierarchies

4. **Memento Pattern** (`Classes/Memento Observer/`)
   - `ScribbleMemento` - Captures and restores scribble state
   - `ScribbleMemento+Friend.h` - Friend class pattern for memento access

5. **Observer Pattern** (`Classes/Memento Observer/`)
   - `ScribbleManager` - Manages scribble notifications

6. **Mediator Pattern** (`Classes/Mediator/`)
   - `CoordinatingController` - Coordinates between view controllers

### Structural Patterns

7. **Composite Pattern** (`Classes/Composite Prototype Iterator/`)
   - `Mark.h` - Component protocol
   - `Dot` - Leaf component (single point)
   - `Stroke` - Composite component (collection of vertices)
   - `Vertex` - Vertex data structure

8. **Proxy Pattern** (`Classes/Proxy/`)
   - `ScribbleThumbnailViewImageProxy` - Lazy-loading image proxy
   - `ScribbleThumbnailView` - Thumbnail view
   - `ScribbleSource.h` - Protocol for scribble data source

### Creational Patterns

9. **Factory Method Pattern** (`Classes/Factory Method/`)
   - `CanvasViewGenerator` - Abstract factory
   - `PaperCanvasViewGenerator` - Concrete factory for paper canvas
   - `ClothCanvasViewGenerator` - Concrete factory for cloth canvas

10. **Prototype Pattern** (`Classes/Composite Prototype Iterator/`)
    - `PrototypeController` - Manages mark prototypes
    - Mark objects support `NSCopying` protocol

## Project Structure

```
TouchPainter/
├── Classes/
│   ├── Command/              # Command pattern implementations
│   ├── Visitor/              # Visitor pattern for mark rendering
│   ├── Iterator/             # Custom iterator for marks
│   ├── Memento Observer/     # Memento & Observer patterns
│   ├── Mediator/             # Mediator pattern coordinator
│   ├── Composite Prototype Iterator/  # Composite & Prototype patterns
│   ├── Proxy/                # Proxy pattern for thumbnails
│   ├── Factory Method/       # Factory Method for canvas creation
│   ├── Views/                # Custom view classes
│   ├── View Controllers/     # MVC view controllers
│   ├── Utilities/            # Helper utilities
│   └── TouchPainterAppDelegate.h/m
├── Resources/
│   └── Images/               # App icons and UI assets
├── main.m
├── MainWindow.xib
├── TouchPainterViewController.xib
├── BridgeView.xib
├── BridgeViewIpad.xib
└── TouchPainter-Info.plist
```

## View Controllers

- **CanvasViewController**: Main drawing canvas with toolbar
- **PaletteViewController**: Color selection interface
- **ThumbnailViewController**: Gallery of saved drawings
- **CoordinatingController**: Mediates between view controllers (Singleton)

## Technical Details

### Frameworks Used
- **UIKit**: UI components
- **Foundation**: Core Objective-C classes
- **CoreGraphics**: Drawing and rendering
- **QuartzCore**: Advanced graphics features

### Platform Support
- iOS 3.0+
- Supports both iPhone and iPad (separate XIB files)
- Uses Automatic Reference Counting (ARC)

### Key Classes

- **Mark Protocol**: Abstract component for Composite pattern
- **Dot**: Represents a single touch point
- **Stroke**: Collection of vertices forming a line
- **Scribble**: Aggregates marks and manages state
- **CanvasView**: Base view for drawing
- **PaperCanvasView/ClothCanvasView**: Concrete canvas implementations

## Utilities

1. **Command Button** (`CommandBarButton`)
   - UIBarButtonItem subclass that executes commands

2. **Command Slider** (`CommandSlider`)
   - UISlider subclass for command-based value changes

3. **Custom Stack** (`NSMutableArray+Stack`)
   - Stack category for undo/redo functionality

4. **View2Image** (`UIView+UIImage`)
   - Category to convert views to images

## Building the Project

1. Open `TouchPainter.xcodeproj` in Xcode
2. Select your target device or simulator
3. Build and run (⌘R)

### Requirements
- Xcode 6.3 or later
- iOS SDK

## Learning Resources

This project is designed to accompany the book:
**"Pro Objective-C Design Patterns for iOS"**

Each design pattern is implemented in isolation, making it easy to:
- Study individual patterns
- Understand pattern interactions
- See practical iOS applications of classic patterns

## Code Organization

The code is organized by design pattern, with clear separation of concerns:
- Pattern-related classes are grouped in directories
- Each pattern has a dedicated folder
- Naming conventions clearly indicate pattern roles (Factory, Command, etc.)

## License

This is educational source code accompanying the *Pro Objective-C Design Patterns for iOS* book.

## Notes

- The project uses XIB files for interface design
- Supports both iPhone and iPad with separate interface files
- Demonstrates practical design pattern usage in a real iOS app
- Code is well-commented for educational purposes
- Each pattern implementation includes relevant GOF pattern concepts

## Design Pattern Summary

| Pattern | Category | Purpose in App |
|---------|----------|----------------|
| Command | Behavioral | Encapsulate drawing actions for undo/redo |
| Visitor | Behavioral | Render marks without modifying mark classes |
| Iterator | Behavioral | Traverse mark hierarchies |
| Memento | Behavioral | Save and restore drawing state |
| Observer | Behavioral | Notify observers of scribble changes |
| Mediator | Behavioral | Coordinate view controller interactions |
| Composite | Structural | Build hierarchical mark structures |
| Proxy | Structural | Lazy-load thumbnail images |
| Factory Method | Creational | Create different canvas types |
| Prototype | Creational | Clone mark objects |

---

*This project demonstrates professional iOS development practices combined with time-tested design patterns for maintainable, extensible code.*
