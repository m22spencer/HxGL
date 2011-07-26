package hxgl.geom;

/**
 * ...
 * @author Matthew Spencer
 */

#if flash
	typedef Rectangle = flash.geom.Rectangle;
#else

class Rectangle 
{

	public function new(x:Float, y:Float, width:Float, height:Float) 
	{
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
	}
	public var x:Float;
	public var y:Float;
	public var width:Float;
	public var height:Float;
}
#end