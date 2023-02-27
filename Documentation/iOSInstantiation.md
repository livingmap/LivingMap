# Instantiating the Living Map Aviation Accelerator

## AviationAccelerator v11.3.3

## iOS SDK
Airline / Airport specific journeys

## Introduction

This document outlines how to integrate and use the AviationAccelerator within an iOS application. The AviationAccelerator connects with a given back end system and, provided matching flight details are submitted, will provide a route between the arrival and departure gates of the loaded airport.

For further support contact [Living Map support](support@livingmap.com)

---

## About the Aviation Accelerator

Living Map provides several industry and client-specific accelerators. An accelerator combines Living Map technologies and products in a consistent and predictable manner for specific use cases.

The Living Map Aviation Accelerator offers support for journeys that take place in and around airport terminals. It has a targeted use case of dealing with customer transfers and in-airport navigation scenarios. 

Full integration with customer's backend service is provided to inform the journeys managed by the AviationAccelerator.

---

## Integration Overview

The AviationAccelerator is targeted to run on iOS v13.0.0+. The following are the suggested software requirements and library dependencies that the AviationAccelerator requires.

---

## Software Recommendations

- MacOS v10.15.4 or newer
- Xcode v13.4 or newer

---

## Dependencies

- LivingMapSDK 11.3.3

It is possible to integrate the AviationAccelerator and associated dependencies via Carthage, Swift Package Manager, CocoaPods, or manually. For further details please refer to the [LivingMap distribution repo](https://github.com/livingmap/LivingMap) or use the below integration guides. Please note the defined dependency versions are required.

---

## Carthage Integration

Carthage is a decentralized dependency manager that builds your dependencies and provides you with binary frameworks. To integrate the AviationAccelerator and its dependencies into your Xcode project using Carthage, specify them in your Cartfile:

An example Cartfile is as follows:

	binary "https://raw.githubusercontent.com/livingmap/distribution-iOS/main/LivingMapSDK.json" == 11.3.3
	binary "https://raw.githubusercontent.com/livingmap/distribution-iOS/main/AviationAccelerator.json" == 11.3.3


Due to the LivingMapSDK being a dependency of the AviationAccelerator, it is required to be loaded in via the cartfile the same way the AviationAccelerator is.

For a completely fresh installation:

    $ carthage bootstrap --use-xcframeworks --platform iOS

To update following a change to your Cartfile:

    $ carthage update --use-xcframeworks --platform ios

To update only the Living Map SDKs (line split for clarity):

    $ carthage update \
          distribution-LivingMapSDK \
          distribution-AviationAccelerator \
          --platform iOS --use-xcframeworks

Once the binary files have been loaded into your Carthage/Build directory, embed them into your Xcode project `build phase → Embed Frameworks`. Alternatively using `general → Frameworks, Libraries, and Embedded content`.

---

## Cocoapods Integration

The AviationAccelerator is hosted on a public github repo, as a result the target source must be explicitly stated for the Cocoapods integration system.  

Use the following as an example:

	source 'https://cdn.cocoapods.org/'
	source 'https://github.com/livingmap/LivingMap.git' 

	platform :ios, '13.0'

	target 'testApp' do
    	use_frameworks!
    	pod 'LivingMapSDK', '11.3.3'
    	pod 'AviationAccelerator', '11.3.3'
	end


Due to the LivingMapSDK being dependency of the AviationAccelerator, it is required to be loaded in via the podfile the same way the AviationAccelerator is.

For a completely fresh installation/update:

    $ pod [install|update]

---

## Swift Package Manager Integration

Swift Package Manager is a tool for automating the distribution of Swift code. It is integrated into Xcode and thus dependencies can be managed via Xcode directly.

Adding the AviationAccelerator and its dependencies can be done through Xcode in the following way:

- In Xcode, navigate to `File -> Add Packages`
- Search using `https://github.com/livingmap/LivingMap` to find the LivingMap Package
- Select the LivingMap package, set the version to v11.3.3 or branch to  main and click Add Package

---

## Configuring your Application

The Living Map SDKs make extensive use of the iPhone’s onboard sensors to perform position calculations. Apple requires that the user be informed explicitly about each of these required capabilities. Several entries must be added to the application’s `info.plist` file. These entries provide messages that are displayed to the user, asking for permission to use specific capabilities. The content of the message is up to the application developer, but these keys must be present. It’s possible to search for the “friendly” property name, or the underlying key name.

| Friendly Name | Key Name | Notes |
| --------- | --------------------- | ----------------------------------------------------------- |
| Privacy - Motion Usage Description | [NSMotionUsageDescription](https://developer.apple.com/documentation/bundleresources/information_property_list/nsmotionusagedescription) | iOS 7.0+ |
| Privacy - Bluetooth Peripheral Usage Description | [NSBluetoothPeripheralUsageDescription](https://developer.apple.com/documentation/bundleresources/information_property_list/nsbluetoothperipheralusagedescription) | Deprecated. iOS 6.0–13.0|
| Privacy - Location Always and When In Use Usage Description | [NSLocationAlwaysAndWhenInUseUsageDescription](https://developer.apple.com/documentation/bundleresources/information_property_list/nslocationalwaysandwheninuseusagedescription) | iOS 11.0+ |
| Privacy - Bluetooth Always Usage Description | [NSBluetoothAlwaysUsageDescription](https://developer.apple.com/documentation/bundleresources/information_property_list/nsbluetoothalwaysusagedescription) | iOS 13.0+ |
| Privacy - Location When In Use Usage Description | [NSLocationWhenInUseUsageDescription](https://developer.apple.com/documentation/bundleresources/information_property_list/nslocationwheninuseusagedescription) | iOS 11.0+ |

---

# Using the Aviation Accelerator

The following are the interfacing classes, structs and protocols that are used to interact with the AviationAccelerator.

## LMAAManager

The API interface that is used to start and stop the AviationAccelerator. It contains the following methods:

```
public class LMAAManager {
        /**
         Start an Aviation Accelerator instance
        
         Given a config object the Accelerator will attempt to register with the backend system.
         Errors and events will be passed back on the event handler object.
        
         - Parameters:
            - eventHandler: A LivingMapEvents instance. This will feedback errors and other journey related events
            - lmaaConfig: The Aviation Accelerator configuration
        
         - Throws: LivingMapError - Aviation Accelerator is already running
        */
        public func start(eventHandler: LivingMapMappingEvents, 
                          lmaaConfig: LMAAConfig) throws {}

        /**
         Stops the running Aviation Accelerator instance. Be sure to call this when your map activity is finished
        */
        public func stop() {}

        /**
         Return the Aviation Accelerator version, as set in the bundle's info.plist
     
         - Returns The framework version
        */
        public static func getVersion() {}
    }

```

## LivingMapMappingEvents

The LivingMapMappingEvents protocol provides a mechanism for user journey events to be passed to your application.

Example Implementation: 

```
public class ViewController: UIViewController, LivingMapMappingEvents {

        // Called when the map has finished loading
        public func mapReady() {}

        // The user has closed the map control
        public func mapClosed() {}

        // Called when a user on a routed journey has reached their destination
        public func destinationReached() {}

        // Custom event fired from within the map control
        public func customEvent(eventId: String, eventParameters: NSArray) {}

        // Generic error handler. SDK errors will be fed back here
        public func errorReceived(error: LivingMapError) {}
    
        // Called when the device connection to the internet changes
        public func onConnectivityStatusChanged(
            connectivityStatus: LivingMapConstants.ConnectivityStatus) {}

        // The location of the blue dot on the map at every update
        public func locationReceived(location: LMLocation) {}
    }
```

## LMAAConfig

Drives the behavior of the AviationAccelerator. It is responsible for defining the Airport the system should run for, map size and position on screen, authentication and flight registration.

Example Implementation: 

```
let customParameters: NSDictionary = [
    "pnrNumber": <PNR FROM APPLICATION>, 
    "gateInitialised": true
]
                
let lmaaConfig = LMAAConfig(
    mapDesignator: MapDesignator(
        airportIataCode: "FRA",               // Airport IATA code
        terminalCode: "T1"                    // Terminal code
    ),
    mapSize: CGRect(                          // Map size and position definition
        x: 0,
        y: 0,
        width: self.view.frame.width,
        height: self.view.frame.height
    ),
    viewController: self,                     // View controller to overlay the map onto.
                                              // This view controller should also implement
                                              // the LivingMapMappingEvents protocol.
    authenticationParameters: AuthenticationParameters(
        clientId: CLIENT_ID,                  // Your Client Id
        clientSecret: CLIENT_SECRET           // Your Client Secret
    ),
    flightRegistrationData: FlightRegistrationData(
        callingAirline: "",                   // Calling airline
        callingApplication: "",               // Calling application id
        inboundFlightDate: Date(),            // Inbound flight date
        inboundFlightNumber: "",              // Inbound flight number
        outboundFlightDate: Date(),           // Outbound flight date
        outboundFlightNumber: ""              // Outbound flight number
    ),
    customParameters: customParameters,       // Custom parameters to pass to Live Location
    gateInitialisedLocation: true             // Defines that a user journey is starting from their gate. It is advised that this is set to true
)

```

In the following descriptions of the above sample code, options marked with (*) are mandatory. Other optional items can be omitted but may impact the journey flow inside the AviationAccelerator if not provided.

airportIataCode * : 
- Defines the airport using standard IATA coding. This will ensure the correct airport is loaded. The chosen airport must be supported by the AviationAccelerator. Supported IATA codes are `LHR`, `FRA`

terminalCode * :
- Defines the airport terminal you wish to interact with. The chosen terminal must be supported by the AviationAccelerator and compatible with the IATA code. Example combination - `FRA`, `T1` or `LHR`, `T2`

mapSize * :
- The size and position of the map to be displayed within your application

viewController * : 
- The view controller that the map should be displayed upon. The view controller is required to implement the LivingMapMappingEvents protocol

authenticationParameters * : 
- The credentials used to gain access to the AviationAccelerator functionality. Separate secrets exist for each application you plan to deploy and Living Map will inform you of the Client ID and Client Secret separately.

flightRegistrationData * :
- This collection provides the information to allow the AviationAccelerator to dynamically request flight data from the DCI services
    - callingAirline : 
        - Name of the airline using this application. e.g Lufthansa -> “LH”
    - callingApplication :
        - Name of the calling application e.g.”LufthansaAirportApp”
    - inboundFlightDate : 
        - The scheduled arrival date and time of the inbound flight
    - inboundFlightNumber :
        - The IATA flight number of the passenger's inbound flight
    - outboundFlightDate : 
        - The scheduled departure date and time of the outbound flight
    - outboundFlightNumber : 
		- The IATA flight number of the passenger's inbound flight

customParameters :
- Custom parameters can modify the operation of the system and provide additional UI in upstream services (such as Live Location) relating to this unique session. In this example the pnrNumber is captured :
```
let customParameters : NSDictionary = ["pnrNumber": 000]
```

## Ending the Session

To allow the AviationAccelerator to gracefully close it is necessary to call the `stop()` method. This will stop the positioning system and all related SDK services.

Calling the `start()` method while there is already an instance of the AviationAccelerator running will result in the `start()` method throwing an error. If you wish to re-initialize the AviationAccelerator, first call `stop()` followed by `start()`.

# Sample Implementations

The following is an example of how you can use the AviationAccelerator. In this example we assume the lmaaConfig is instantiated in the same way as that in the `LMAAConfig` section above.

### Starting the LMAAManager

```
import AviationAccelerator
import LivingMapSDK

class ViewController: UIViewController, LivingMapMappingEvents {

    let lmaaManager = LMAAManager()
    let lmaaConfig = LMAAConfig(...)

    override func viewDidLoad() {
        super.viewDidLoad()

        do {
            try lmaaManager.start(eventHandler: self, lmaaConfig: lmaaConfig)
        } catch {
            print("There is already an instance of the AA running")
        }
    }

    override func viewWillDisappear(_ animated: Bool) {
        lmaaManager.stop()
    }

    public func mapReady() {}
    public func destinationReached() {}
    public func customEvent(eventId: String, eventParameters: NSArray) {}
    public func errorReceived(error: LivingMapError) {}    
    public func onConnectivityStatusChanged(connectivityStatus: LivingMapConstants.ConnectivityStatus) {}
    public func locationReceived(location: LMLocation) {}
}
```

# Error Recovery

In the event of a serious unrecoverable problem the user will be presented with
an error dialog.

Pressing Try Again will result in the AviationAccelerator attempting to recover. Pressing Exit will raise an error callback via the `errorReceived()` handler in the `LivingMapMappingEvents` interface.  

This error will contain a LivingMapError object with an error severity and error code. At this point the integrator of the AviationAccelerator will need to test the severity and ensure that the `stop()` method is called in the event of any Error or Fatal_Error problems. 

An example implementation of the error handling using the errorReceived callback:

```
public func errorReceived(error: LivingMapError) {
    NSLog("Error Received: %@", error.errorMessage)

    if error.severity == .fatalError {
        lmaaManager.stop()
    }
}
```

Warnings are raised for information only and don’t require the SDK to be stopped but it’s useful for support purposes to log the message to the application debug console.

# Device Calibration

Due to the sensory requirements of the AviationAccelerator, it is required that device calibration is completed when prompted. Calibration of a device is handled by the AviationAccelerator and a popup will be shown over the map when calibration is detected to be required.

If the cancel button is selected, then the SDK will rely on the device's calibrated sensor values, whose quality varies by device and whether the phone has been online long enough to self-calibrate successfully. It is recommended that the user is encouraged to perform calibration at this stage.

# Known Issues 

1- map won't load on (ios < 13.4 and iOS 14.x.x ) due to a Safari issue with the tiles loading (emulator tested only).

<B><i> Detalis </i></B>: 
LivingMapSDKs map webview uses third party dependency mapbox.
[mapbox](https://www.mapbox.com) faces some issues with Safari application in certain versions of xcode emulators, [problem report](https://github.com/mapbox/mapbox-gl-js/issues/10260). The problem been fixed in iOS 15 emulators.