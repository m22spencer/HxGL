package hxgl;

#if flash
    typedef Lib = flash.Lib;
#else
import hxgl.display.Stage;
import hxgl.core.HXGL;

class Lib
{
    public static var stage(GET_STAGE, never):Stage;
	static var _stage:Stage = untyped new Stage ();
	
	static function GET_STAGE():Stage
	{
		return _stage;
	}
	
	public static function init (cb:Dynamic->Void)
	{
		trace ("Attempting link");
		stage.addEventListener ("__INIT__", cb);
		trace ("Added evt");
		HXGL.LINK_LIB ();
		trace ("Linked");
		HXGL.setEnterFrame (__initdone__);		//Register an enterframe to __initdone__ so execution continues past HXGL_init;
		HXGL.init (0, 0);	//blocking function	  
	}
	
	static function __initdone__ ()
	{
		untyped stage.extern_registerOnEnterFrame ();		//Assign extern enterframe handler to event "system"
		stage.dispatchEvent ("__INIT__");					//Resume execution via cb:Dynamic->Void
	}

	public static function getTimer ()
	{
		#if cpp
        return Std.int (cpp.Sys.cpuTime () * 1000);
		#end
	}
}

#end
