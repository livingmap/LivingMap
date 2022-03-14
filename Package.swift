// swift-tools-version:5.5
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "LivingMap",
    platforms: [.iOS(.v13)],
    products: [
        // Products define the executables and libraries a package produces, and make them visible to other packages.
        .library(
            name: "LivingMap",
            targets: ["LivingMapSDK", "LivingMapLiveSDK", "AviationAccelerator"]),
    ],
    dependencies: [],
    targets: [
        .binaryTarget(name: "LivingMapSDK",
                      path: "Sources/LivingMapSDK.xcframework"
                     ),
        .binaryTarget(name: "LivingMapLiveSDK",
                      path: "Sources/LivingMapLiveSDK.xcframework"
                     ),
        .binaryTarget(name: "AviationAccelerator",
                      path: "Sources/AviationAccelerator.xcframework"
                     ),

    ]
)
