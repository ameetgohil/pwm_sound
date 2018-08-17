// Plays a familiar melody using PWM to the headphones. To find the frequencies of notes,
// see http://en.wikipedia.org/wiki/Piano_key_frequencies

#include "mbed.h"

#define VOLUME 0.01
#define BPM 100.0

PwmOut pwm_pin(p21);

// Plays a sound with the defined frequency, duration, and volume
void playNote(float frequency, float duration, float volume) {
    pwm_pin.period(1.0/frequency);
    pwm_pin = volume/2.0;
    wait(duration);
    pwm_pin = 0.0;
}

int main() {
    float beat_duration;
    
    // Calculate duration of a quarter note from pwm
    beat_duration = 60.0/BPM;
    
    // loop forever
    while (1) {
        
        // First measure
        playNote(391.995, (beat_duration - 0.1), VOLUME);
        wait(0.1);
        playNote(391.995, (beat_duration - 0.1), VOLUME);
        wait(0.1);
        playNote(391.995, (beat_duration - 0.1), VOLUME);
        wait(0.1);
        playNote(311.127, (0.75 * beat_duration), VOLUME);
        playNote(466.164, (0.25 * beat_duration), VOLUME);

        // Second measure
        playNote(391.995, (beat_duration - 0.1), VOLUME);
        wait(0.1);
        playNote(311.127, (0.75 * beat_duration), VOLUME);
        playNote(466.164, (0.25 * beat_duration), VOLUME);
        playNote(391.995, ((2 * beat_duration) - 0.1), VOLUME);
        wait(0.1);

        // Third measure
        playNote(587.330, (beat_duration - 0.1), VOLUME);
        wait(0.1);
        playNote(587.330, (beat_duration - 0.1), VOLUME);
        wait(0.1);
        playNote(587.330, (beat_duration - 0.1), VOLUME);
        wait(0.1);
        playNote(622.254, (0.75 * beat_duration), VOLUME);
        playNote(466.164, (0.25 * beat_duration), VOLUME);

        // Fourth measure
        playNote(369.994, (beat_duration - 0.1), VOLUME);
        wait(0.1);
        playNote(311.127, (0.75 * beat_duration), VOLUME);
        playNote(466.164, (0.25 * beat_duration), VOLUME);
        playNote(391.995, ((2 * beat_duration) - 0.1), VOLUME);
        wait(0.1);
    }
}
