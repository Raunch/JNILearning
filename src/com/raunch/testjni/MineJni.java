package com.raunch.testjni;

public class MineJni {
	public String mHello;
	public static int mWorld;
	public MineJni() {		
	}
	
	public String getJniTest() {
		return getTestString("Haha");
	}
//	
//	public int getSumArray(int[] arr) {
//		return sumArray(arr);
//	}
	public native void accessField();
	
	public native String getTestString(String test); 
	
	public native int sumArray(int[] test);
	
	public native int[][] initInt2DArray(int size);

}
