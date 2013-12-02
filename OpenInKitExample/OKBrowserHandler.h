#import "OKHandler.h"

/** An instance of `OKBrowserHandler` opens http and https URLs in a third-party web browser. */
@interface OKBrowserHandler : OKHandler

/** Opens a URL 
 @param url A URL to open. Must have either `http:` or `https:` as its scheme. 
 @return A `UIActivityViewController` to present modally if the user must pick a third-party app. Otherwise nil. */
- (UIActivityViewController *)openURL:(NSURL *)url;

/** Opens a URL with a callback
 @param url A URL to open. Must have either `http:` or `https:` as its scheme.
 @param callback A URL to be opened by the third-party app when the action has been completed.
 @see openURL:
 @return A `UIActivityViewController` to present modally if the user must pick a third-party app. Otherwise nil. */
- (UIActivityViewController *)openURL:(NSURL *)url withCallback:(NSURL *)callback;

@end
