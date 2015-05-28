package com.raunch.testjni;

public class MineJni {
	public MineJni() {		
	}
	
	public String getJniTest() {
		return getTestString("Haha");
	}
	
	public native String getTestString(String test); 

}
