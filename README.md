# LivingMap

Technology solutions for complex spaces. Digital mapping, wayfinding and positioning for people, assets and places.

Visit [livingmap.com](https://www.livingmap.com/) to learn more.

![](https://img.shields.io/badge/Swift:-5.3_5.4_5.5-ff5900.svg)
![](https://img.shields.io/badge/Platform:-_iOS-ff5900.svg)
![](https://img.shields.io/badge/Pod:-_v5.5.0-ff5900.svg)
![](https://img.shields.io/badge/Carthage:-_compatible-ff5900.svg)
![](https://img.shields.io/badge/Swift_Package_Manager:-compatible-ff5900.svg)

LivingMapSDK is a Swift binaries that provides mapping, routing, positioning and tracking in a multitude of indoor and outdoor environments.

- [Features](#features)
- [Requirements](#requirements)
- [Versions](#versions)
- [Installation](#installation)
- [Requirements](#requirements)
- [Permissions](#permissions)

## Features

#### Live Positioning

    - No hardware dependency
    • 1-5 metre location accuracy
    • Real-time asset tracking
    • Utilises existing infrastructure

#### Live Map

    • Dynamic category overlays
    • Customisable asset list
    • Category and type search
    • API integrations - track and visualise data from IoT devices and external databases
    • Asset management

#### Live Routing

    • Customise routing with business rules
    • GDPR compliant
    • Alerts via push notification based on time, location or both
    • Accessible routing tailored to users’ needs
    • Routing between and within indoor and outdoor spaces

#### Live Location

    • Real-time information and intelligence
    • Access to historic data and trends
    • Advanced data visualisation charts and dashboards
    • Real-time notifications based on customer parameters
    • GDPR compliant

## Requirements

| Platform  | Minimum Swift Version | Installation                                                                                                         | Status       |
| --------- | --------------------- | -------------------------------------------------------------------------------------------------------------------- | ------------ |
| iOS 13.0+ | 5.3                   | [CocoaPods](#cocoapods), [Carthage](#carthage), [Swift Package Manager](#swift-package-manager), [Manual](#manually) | Fully Tested |

## Installation

### CocoaPods

---

[CocoaPods](https://cocoapods.org) is a dependency manager for Cocoa projects. For usage and installation instructions.

In order to use the framework artefacts linked by this repo a slight modification to your podfile is necessary.

You must explicitly state that this repo is a source for the Cocopods integration system. Add this line of code under the platform declaration but above the project declaration in the podfile.

```
source 'git@github.com:livingmap/LivingMap.git'
```

Point to the latest version:-

```ruby
    pod 'LivingMapSDK'
    pod 'LivingMapLiveSDK'
    pod 'AirlineAccelerator'
```

Point to the specific version (recommended):-

```ruby
    pod 'LivingMapSDK', '11.1.0'
    pod 'LivingMapLiveSDK', '11.1.0'
    pod 'AirlineAccelerator', '11.1.0'
```

To install or update your new dependencies, from terminal run:

```ruby
    pod [install|update]
```

### Carthage

---

[Carthage](https://github.com/Carthage/Carthage) is a decentralized dependency manager that builds your dependencies and provides you with binary frameworks. To integrate LivingMapSDKs into your Xcode project using Carthage, specify it in your `Cartfile`:

Point to the latest version:-

```ogdl
binary "https://raw.githubusercontent.com/livingmap/LivingMap/main/LivingMapSDK.json"
binary "https://raw.githubusercontent.com/livingmap/LivingMap/main/LivingMapLiveSDK.json"
binary "https://raw.githubusercontent.com/livingmap/LivingMap/main/AviationAccelerator.json"
```

Point to the specific version (recommended):-

```ogdl
binary "https://raw.githubusercontent.com/livingmap/LivingMap/main/LivingMapSDK.json" == 11.1.0
binary "https://raw.githubusercontent.com/livingmap/LivingMap/main/LivingMapLiveSDK.json" == 11.1.0
binary "https://raw.githubusercontent.com/livingmap/LivingMap/main/AviationAccelerator.json" == 11.1.0
```

To download the dependencies use the following command in the project directory:

`carthage update --use-xcframeworks --platform ios`

To clear carthage cache before updating:

`rm -rf ~/Library/Caches/org.carthage.CarthageKit`

Attach the downloaded frameworks/xcFrameworks which are located in the `<project>/Carthage/Build` directory
to the project through one of the following approaches:

- In the project tabs General --> Frameworks, Libraries, and Embedded Content
- In the project tabs Build Phases --> Embed Frameworks

Ensure the frameworks/xcFrameworks are embedded and signed.

### Swift Package Manager

---

he [Swift Package Manager](https://swift.org/package-manager/) is a tool for automating the distribution of Swift code.
It is integrated into Xcode and thus dependencies can be managed via Xcode directly.

Adding LivingMapSDKs and its dependencies can be done through Xcode in the following way:

- In Xcode, navigate to `File -> Add Packages`
- Search using `https://github.com/livingmap/LivingMap` to find the LivingMap Package
- Select the LivingMap package, set the version to v11.1.0 and click Add Project

### Permissions

---

Ensure your app implements `Location Updates` capability and prompts the user for `Location Permissions`.

.. attention:: **Screen Orientation and Mapping** – Only portrait-mode is supported by _LivingMapSDK_ when Mapping is used. Applications which integrate the SDK and use Mapping must ensure it is locked to Portrait-mode through its configuration.
