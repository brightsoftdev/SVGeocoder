//
// SVGeocoder.h
//
// Created by Sam Vermette on 07.02.11.
// Copyright 2011 samvermette.com. All rights reserved.
//
// https://github.com/samvermette/SVGeocoder
// http://code.google.com/apis/maps/documentation/geocoding/
//

#import <Foundation/Foundation.h>
#import <AddressBook/AddressBook.h>
#import <CoreLocation/CoreLocation.h>
#import <MapKit/MapKit.h>

#import "SVPlacemark.h"

@protocol SVGeocoderDelegate;

@interface SVGeocoder : NSObject

@property (nonatomic, assign) id<SVGeocoderDelegate> delegate;

// Reverse Geocoder
- (SVGeocoder*)initWithCoordinate:(CLLocationCoordinate2D)coordinate;

// (forward) Geocoder
- (SVGeocoder*)initWithAddress:(NSString *)address;
- (SVGeocoder*)initWithAddress:(NSString *)address inBounds:(MKCoordinateRegion)bounds;
- (SVGeocoder*)initWithAddress:(NSString *)address inRegion:(NSString *)regionString;

- (void)startAsynchronous;
- (void)cancel;

@end


@protocol SVGeocoderDelegate

@optional
- (void)geocoder:(SVGeocoder *)geocoder didFindPlacemark:(SVPlacemark *)placemark; // SVPlacemark is an MKPlacemark subclass with a coordinate property
- (void)geocoder:(SVGeocoder *)geocoder didFindPlacemarks:(NSArray *)placemarks; // array of SVPlacemark objects
- (void)geocoder:(SVGeocoder *)geocoder didFindPlacemarksRaw:(NSArray *)placemarks; // array of SVPlacemark raw data
- (void)geocoder:(SVGeocoder *)geocoder didFailWithError:(NSError *)error;

@end