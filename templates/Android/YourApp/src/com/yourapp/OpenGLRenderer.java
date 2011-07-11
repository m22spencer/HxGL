package com.yourapp;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLU;
import android.opengl.GLSurfaceView.Renderer;

public class OpenGLRenderer implements Renderer {
	public void onSurfaceCreated(GL10 gl, EGLConfig config)
	{
		gl.glClearColor((float)0.0,(float)0.0,(float)0.0,(float)0.5);
		gl.glShadeModel(GL10.GL_SMOOTH);
		gl.glClearDepthf(1.0f);
		gl.glEnable(GL10.GL_DEPTH_TEST);
		gl.glDepthFunc(GL10.GL_LEQUAL);
		gl.glHint(GL10.GL_PERSPECTIVE_CORRECTION_HINT,
				  GL10.GL_NICEST);
	}
	public void onDrawFrame (GL10 gl)
	{
		com.hxgl.HXGL.run("hxgl");
	}
	
	public void onSurfaceChanged (GL10 gl, int width, int height)
	{
		gl.glViewport(0, 0, width, height);
		gl.glMatrixMode(GL10.GL_PROJECTION);
		gl.glLoadIdentity();
		GLU.gluPerspective(gl, 45.0f,
				(float)width/(float)height,
				0.1f,100.0f);
		gl.glMatrixMode(GL10.GL_MODELVIEW);
		gl.glLoadIdentity();
	}
}
