package chapter9_examples;

class TV {
	int channel; // The current channel
	int volumeLevel; // The current volume level
	boolean on; // Indicates whether this TV is on or off

	// Construct a tv
	TV() {
		channel = 1; // Default channel is 1
		volumeLevel = 1; // Default volume level is 1
		on = false; // By default TV is off
	}

	// Turn this TV on
	void turnOn() {
		if (!on)
			on = true;
	}

	// Turn this TV off
	void turnOff() {
		if (on)
			on = false;
	}

	// Set a new channel
	void setChannel(int newChannel) {
		if (on && newChannel >= 1 && newChannel <= 120)
			channel = newChannel;
	}

	// Set a new volume
	void setVolume(int newVolumeLevel) {
		if (on && newVolumeLevel >= 1 && newVolumeLevel <= 7)
			volumeLevel = newVolumeLevel;
	}

	// Increase the channel by 1
	void channelUp() {
		if (on && channel < 120)
			channel++;
	}

	// Decrease the channel by 1
	void channelDown() {
		if (on && channel > 1)
			channel--;
	}

	// Increase the volume by 1
	void volumeUp() {
		if (on && volumeLevel < 7)
			volumeLevel++;
	}

	// Decrease the volume by 1
	void volumeDown() {
		if (on && volumeLevel > 1)
			volumeLevel--;
	}
}
