package com.theopentutorials.exception;

public class ApplicationException extends Exception {

	private static final long serialVersionUID = -982311242179235036L;

	public ApplicationException(){
		
	}
	
	public ApplicationException(String message){
		super(message);
	}

	public ApplicationException(String message, Throwable cause) {
		super(message, cause);
	}
	
}
