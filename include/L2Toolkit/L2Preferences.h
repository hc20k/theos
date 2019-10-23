@interface L2Preferences : NSObject
+(instancetype)sharedInstance;
-(id)preferencesDictionary;
-(void)setPreferenceValue:(id)value forKey:(NSString*)key;
@property(atomic,assign) NSURL* preferencesURL;
@property(atomic,assign) NSString* postNotification;
@end
