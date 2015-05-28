package com.raunch.testjni;

import android.app.Application;

public class TestApp extends Application {

	@Override
	public void onCreate() {
		// TODO Auto-generated method stub
		super.onCreate();
		System.loadLibrary("minejni");
	}

}
