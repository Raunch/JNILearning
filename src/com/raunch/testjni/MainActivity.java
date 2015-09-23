package com.raunch.testjni;

import android.app.Activity;
import android.content.Context;
import android.content.pm.PackageManager.NameNotFoundException;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;


public class MainActivity extends Activity {
	 MineJni test;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        //System.loadLibrary("minejni");
        test = new MineJni();
        Log.i("Test","The jni test log is " + test.getJniTest());
        testAccessField();
        //MineJni test = new MineJni();
        //Log.i("Test","The jni test log is " + test.getJniTest());
        try {
			Context context = Context.class.newInstance();
			context = context.createPackageContext("com.raunch.testjni", Context.CONTEXT_IGNORE_SECURITY);
			String test = context.getPackageName();
			Log.i("Test","Fucking here ..... and the packagename is " + test);
		} catch (InstantiationException e) {
			// TODO Auto-generated catch block
			Log.i("Test","Fucking here 111");
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			// TODO Auto-generated catch block
			Log.i("Test","Fucking here 111222");
			e.printStackTrace();
		} catch (NameNotFoundException e) {
			// TODO Auto-generated catch block
			Log.i("Test","Fucking here 111333");
			e.printStackTrace();
		}
        
    }
    
    public void testAccessField() {
    	test.mHello="hello world";
    	MineJni.mWorld = 100;
    	test.accessField();
    	Log.i("Test","After change, the string is " + test.mHello + " and the world is " + MineJni.mWorld);
    }
    
    public void testInit2DArray() {
    	 int[][] out = test.initInt2DArray(3);
         for(int i=0; i<3; i++) {
         	for (int j=0 ; j<3; j++) {
         		Log.i("Test", "The output is " + out[i][j]);
         	}
         }
    }
    
    public void testSumArray() {
    	int arr[] = new int[10];
        for(int i=0; i<10; i++) {
        	arr[i] = i;
        }
    	Log.i("Test","The test int array sum is " +  test.sumArray(arr));
    }
    


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();
        if (id == R.id.action_settings) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
}
