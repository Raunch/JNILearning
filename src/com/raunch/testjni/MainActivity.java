package com.raunch.testjni;

import android.app.Activity;
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
