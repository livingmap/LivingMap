// swift-tools-version:5.5
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "LivingMap",
    platforms: [.macOS(.v10_12),
                .iOS(.v10),
                .tvOS(.v10),
                .watchOS(.v3)],
    products: [
        // Products define the executables and libraries a package produces, and make them visible to other packages.
        .library(
            name: "LivingMap",
            targets: ["LivingMapSDK", "LivingMapLiveSDK", "AirlineAccelerator", "LivingMap"]),
    ],
    dependencies: [
        .package(name: "Alamofire", url: "https://github.com/Alamofire/Alamofire.git", .exact("5.4.3")),
        .package(name: "SwiftProtobuf", url: "https://github.com/apple/swift-protobuf.git", from: "1.6.0")
    ],
    targets: [
        .binaryTarget(name: "LivingMapSDK",
                      path: "Sources/LivingMapSDK.xcframework"
                     ),
        .binaryTarget(name: "LivingMapLiveSDK",
                      path: "Sources/LivingMapLiveSDK.xcframework"
                     ),
        .binaryTarget(name: "AirlineAccelerator",
                      path: "Sources/AirlineAccelerator.xcframework"
                     ),
        .target(name: "LivingMap",
                dependencies: ["Alamofire", "SwiftProtobuf"]
               ),

    ]
)
