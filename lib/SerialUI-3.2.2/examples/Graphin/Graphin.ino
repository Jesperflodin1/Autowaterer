
/*
 * Graphin.ino -- sample showing some tracked vars/graphs
 * Setup of SerialUI and menu system
 * Pat Deegan
 * Psychogenic.com 
 * 
 * Copyright (C) 2019 Pat Deegan, psychogenic.com
 * 
 * Generated by DruidBuilder [https://devicedruid.com/], 
 * as part of project "f1cce9edcde145b08daf90b107f23f128y5gJi5v7c",
 * aka Graphin.
 * 
 * Druid4Arduino, Device Druid, Druid Builder, the builder 
 * code brewery and its wizards, SerialUI and supporting 
 * libraries, as well as the generated parts of this program 
 * are 
 *            Copyright (C) 2013-2019 Pat Deegan 
 * [https://psychogenic.com/ | https://inductive-kickback.com/]
 * and distributed under the terms of their respective licenses.
 * See https://devicedruid.com for details.
 * 
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE 
 * PROGRAM IS WITH YOU. SHOULD THE PROGRAM PROVE DEFECTIVE, 
 * YOU ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR
 * CORRECTION.
 * 
 * Keep in mind that there is no warranty and you are solely 
 * responsible for the use of all these cool tools.
 * 
 * Play safe, have fun.
 * 
 */


/* we need the SerialUI lib */
#include <SerialUI.h>
#include "GraphinSettings.h"

/* our project specific types and functions are here */
#include "Graphin.h"



/* 
 * In addition to any custom globals you declared,
 * here you have access to:
 * 
 * *** MySUI -- the SerialUI instance.
 * Use it as you would the Serial device, e.g.
 * 	MySUI.println(F("Helloooo..."));
 * 	
 * 	
 * *** MyInputs -- a container for 
 * values submitted by users. Contents:
 *  
 *    MyInputs.Baseline (BoundedLong)
 *  
 *  
 *  
 * *** MyTracked -- a container for values tracked
 * by druid and displayed to users in "state" pane.  Changes to:
 * 
 *    MyTracked.Triangle (SerialUI::Tracked::Integer)
 *    MyTracked.Sine (SerialUI::Tracked::Float)
 *    MyTracked.Who (SerialUI::Tracked::String)
 *    MyTracked.Setting (SerialUI::Tracked::Float)
 * 
 * will automatically be reported to the UI, on the next refresh/ping.
 * 
 * 
 */


// generated for usbserial platform

#if SERIALUI_VERSION_AT_LEAST(3,0)
// all is well, you have a valid SerialUI lib installed...
#else
#error "Need SerialUI version 3.0 or greater"
#endif

// Simple authentication -- only available on
//  BLE (nRF5/BLE Nano etc)
//  Linux/Raspberry Pi
// by default
// SerialUI::Auth::Simple SimpleAuth("guestpass", "userpass", "adminpass");

/* **** standard setup() function **** */
void setup() {

	if (!SetupSerialUI()) {
		DIE_HORRIBLY(F("Problem during setup"));
	}
  // If using authentication, uncomment:
  // SerialUI::Globals::setAuthenticator(&SimpleAuth);

}

void loop() {

  /* We checkForUser() periodically, to see
  ** if anyone is attempting to send us some
  ** data through SerialUI.
  **
  ** This code checks at every pass of the main
  ** loop, meaning a user can interact with the 
  ** system at any time.  Should you want to
  ** check for user access only once (say have a
  ** N second wait on startup, and then forgo
  ** allowing SerialUI access), then increase the
  ** delay parameter and use checkForUserOnce(), e.g.
  **
  **    mySUI.checkForUserOnce(15000);
  **
  ** to allow 15 seconds to connect on startup only.
  **
  ** Called without parameters, or with 0, checkForUser 
  ** won't delay the program, as it won't block at all.
  ** Using a parameter > 0:
  **	checkForUser(MAX_MS);
  ** will wait for up to MAX_MS milliseconds for a user,
  ** so is equivalent to having a delay(MAX_MS) in the loop,
  ** when no user is present.
  */
  if (MySUI.checkForUser()) {
    
    /* Now we keep handling the serial user's
    ** requests until they exit or timeout.
    */
    while (MySUI.userPresent()) {
      // actually respond to requests, using
      MySUI.handleRequests();


	  // you could add a quick task here, to perform
	  // after *every* request, but it's better to use
	  // the setUserPresenceHeartbeat-related methods
    }
  } /* end if we had a user on the serial line */
  
  // add code here to run when no ones around
  

}