/**
 * ...
 * @author Matthew Spencer
 */

package hxgl.events;

#if flash
typedef Event = flash.events.Event;
#else
class Event 
{
	public static var CONTEXT3D_CREATE : String = "context3DCreate";	//FIXME No access to internet, don't know what this is supposed to actually be.
}
#end
