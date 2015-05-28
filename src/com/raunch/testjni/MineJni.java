package com.raunch.testjni;

public class MineJni {
	public MineJni() {		
	}
	
	public String getJniTest() {
		return getTestString();
	}
	
	public native String getTestString(); 

}
