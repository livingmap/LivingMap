# Carthage distribution Readme:

## Introduaction

this repo is designed to to hold livingMap iOS SKDs binary frameworks/xcFrameworks for Carthage distribution. 


## Versions

Latest: 10.3.6  
Stable: 10.3.6 

### Using custom carthage frameworks/xcFrameworks

in order to use the frameworks/xcFrameworks linked by this repo the XCode Project the link to the distributing json files that includes the valide releases connected to tags with SDKs frameworks/xcFrameworks as tags attachments. 

the following lines need to be added to the project cartFile. 

to use a specific version for instance `10.3.6`:

```
 binary "https://raw.githubusercontent.com/livingmap/distribution-iOS/main/LivingMapSDK.json" == <version>
 binary "https://raw.githubusercontent.com/livingmap/distribution-iOS/main/LivingMapLiveSDK.json" == <version>
 binary "https://raw.githubusercontent.com/livingmap/distribution-iOS/main/AviationAccelerator.json" == <version>
```

or to get the latest version use: 

```
 binary "https://raw.githubusercontent.com/livingmap/distribution-iOS/main/LivingMapSDK.json" 
 binary "https://raw.githubusercontent.com/livingmap/distribution-iOS/main/LivingMapLiveSDK.json"
 binary "https://raw.githubusercontent.com/livingmap/distribution-iOS/main/AviationAccelerator.json"
```

to download the dependecies use the following command in the project deirectory

`carthage update --use-xcframeworks --platform ios`

to clear carthage cache before update

`rm -rf ~/Library/Caches/org.carthage.CarthageKit`

the frameworks/xcFrameworks downloaded in the `<project>/Carthage/Build` directory 
attach the frameworks/xcFrameworks in the project through one of the following approaches:

-  in the project tabs General --> Frameworks, Libraries, and Embedded Content 

-  in the project tabs Build Phases --> Embeded Frameworks

make sure the frameworks/xcFrameworks embeded and signed. 

## SDKs Dependencies 

- Alamofire v5.4.3
- SwiftProtobuf 

## Adding a new frameworks/xcFrameworks

Deploying a new framework relatively straightforward. Create a new tag for each binary framework according to the frameworks/xcFrameworks version. Attach frameworks/xcFrameworks to the it's respective tags. 
Update json file to include the new tags versions and binary attahments links. 

##References 

- https://github.com/Carthage/Carthage

- https://kevinle.medium.com/step-by-step-guide-on-using-carthage-dependency-manager-a29c15f9a1ac
