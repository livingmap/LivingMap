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



# distribution-Specs Readme

## Introduction

This repo is designed to hold all the Cocoapod specifications for our distribution build artefacts for iOS.

The specifications in turn each point to their own repo where the actual artefacts are stored.

## Using the Custom Specs Repo

In order to use the framework artefacts linked by this repo a slight modification to XCode project podfile is necessary.

You must explicitly state that this repo is a source for the Cocopods integration system. Add this line of code under the platform declaration but above the project declaration in the podfile.

```
source 'git@github.com:livingmap/distribution-Specs.git'
```

The Cocoapods trunk is implicit if there is no other source specified. The inclusion of the Livingmap source (or any other source) necessitates the explicit inclusion or the Cocoapods source too.

```
source 'https://github.com/CocoaPods/Specs.git'
```

Therefore, if you are only adding the Livingmap distibution-Specs source then these two lines of code need to be added (below the platform declaration and above the project declaration):

```
source 'https://github.com/CocoaPods/Specs.git'
source 'git@github.com:livingmap/distribution-Specs.git'
```

On running a `pod update` these repos will be added to your `<home>/.Cocoapods/repos/` directory.

NOTE: If this is the first time you are having to explicitly state the source the entirety of the Cocoapods repo needs to be downloaded. This takes a while (~ 5-10 mins).

Once that has completed then you can now import Livingmap frameworks in the same syntactical way as one would any other framework i.e:

`pod 'AirlineAccelerator'`
or
`pod 'AirlineAccelerator', '0.5.6'`

## Adding Specs to the Repo

Deploying a new framework relatively straightforward. Push the new framework to it's respective repo and tag according to the version. Ensure that you update the Podspec. 

NOTE: Podspecs are included in the individual distribution repos for the frameworks but this is just to keep track of them. They are not used in the Cocoapods integration system.

NOTE: In the `<home>/.Cocoapods/Repo\` directory there will be a 'livingmap' directory. This is the reference that the Cocoapods system uses once it has pulled it from our repo.

Once you have updated the Podspec for the new framework then you need to use the command below. This command has the dual functionality of adding the podspec to your .Cocoapods repo and pushing the podspec to the livingmap/distribution-Specs repo on Github. It has the dual benefit of adding the podspecs in a file structure that Cocoapods can parse (allowing version selection).

WARNING: The command below assumes that the livingmap distribution-Specs source is already in your `<home>/.Cocoapods/repos/` directory. If you are trying to perform this step without first using the Cocopods, as described in the above section - 'Using Custom Specs Repo', then you will need an additional command to retrieve the directory. This command is detailed in reference linked below but has been omitted here for simplicity's sake.

```
pod repo push REPO_NAME SPEC_NAME.podspec
```

That's it.

## References

[Cocoapods Private Pods](https://guides.cocoapods.org/making/private-cocoapods.html)

