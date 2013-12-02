#import <UIKit/UIKit.h>

/** A subclass of `UIActivity` that presents a single third-party application capable of opening a given URL scheme or set of URL schemes.
 
 Typically, the dictionary of accepted URL schemes and the name of the application should come from the contents of a plist file and its filename, respetively. In practice, you shouldn't need to manually initialize an `OKActivity` outside of the `OKHandler` class.
 
 @warning `OKActivity`'s implementation of the `UIActivity` method `canPerformWithActivityItems:` always returns `YES`. It is your responsibility to ensure that an OKActivity can actually respond to a URL (using `isAvailableForCommand:arguments:`) before adding it to a `UIActivityViewController`
 
 @warning `OKActivity` currently makes use of the private method `_activityImage` to coax the `UIActivityViewController` into displaying a full-color image rather than creating a black-and-white representation using the `UIImage` returned by `activityImage` as a mask. It remains to be seen whether Apple will allow this private API usage or not. */
@interface OKActivity : UIActivity

/** The name of the app, to be displayed as the `UIActivity` `activityTitle` field. */
@property (strong, nonatomic) NSString *name;

/** A dictionary of URL schemes an application responds to. The keys are command names, and the arguments are handlebar-templated strings that can be used to construct a valid URL. */
@property (strong, nonatomic) NSDictionary *dict;

/** Returns an intialized `OKActivity` object.

 @param dict The dictionary mapping commands to valid URL schemes for the third-party application.
 @param name The name of the third-party application.
 @param application The UIApplication to use when calling `[UIApplication openURL:]` and `[UIApplication canOpenURL:]`. You probably want this to be `[UIApplication sharedApplication]`, but it is injected here for test purposes.
 
 @return an initialized `OKActivity` object. */
- (instancetype)initWithDictionary:(NSDictionary *)dict
                              name: (NSString *)name
                       application:(UIApplication *)application;

/** Checks whether or not the third-party app can accept a custom URL corresponding to a given command
 
 @param command A command to perform. If the third-party app knows how to perform this command, it should have a corresponding key in the activity's `dict` property.
 @param args A dictionary of arguments whose keys correspond to templating variable names in the activity's `dict` value for the given command.
 
 @return YES if the third-party app responds to a custom URL scheme to perform the corresponding command.*/
- (BOOL)isAvailableForCommand:(NSString *)command arguments:(NSDictionary *)args;

@end
