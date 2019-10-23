#import <Preferences/PSSpecifier.h>
#import <Preferences/PSListController.h>
#import <Preferences/PSEditableListController.h>
#import <Preferences/PSTableCell.h>

#import "L2UIToolkit.h"

@interface L2UIListController : PSListController <UITextFieldDelegate>
-(NSURL*)preferencesURL; //OVERRIDE ME
@end
