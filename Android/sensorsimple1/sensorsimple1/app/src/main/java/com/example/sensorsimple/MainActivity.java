package com.example.sensorsimple;
import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;
import android.widget.Toast;
import android.hardware.SensorManager;
import android.hardware.SensorEventListener;
import android.hardware.SensorEvent;
import android.hardware.Sensor;
import java.util.List;
public class MainActivity extends Activity {
	SensorManager sm = null;
	TextView accText = null;
	List list;

	/* This responds to sensor events */
	SensorEventListener sel = new SensorEventListener(){
		public void onAccuracyChanged(Sensor sensor, int accuracy) {
			/* Isn't required for this example */

		}
		public void onSensorChanged(SensorEvent event) {
			/* Write the accelerometer values to the TextView */
			float[] values = event.values;
			accText.setText("x: "+values[0]+"\ny: "+values[1]+"\nz: "+values[2]);
		}

	};

    /* Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        /* Get a SensorManager instance */
        sm = (SensorManager)getSystemService(SENSOR_SERVICE);

        /* This corresponds to a TextView element in main.xml with android:id="@+id/accText" */
        accText = (TextView)findViewById(R.id.textView1);

        /* Get list of accelerometers */
        list = sm.getSensorList(Sensor.TYPE_ACCELEROMETER);

        /* If there are any accelerometers register a listener to the first else
           print a little error message */
        if(list.size()>0){
        	sm.registerListener(sel, (Sensor) list.get(0), SensorManager.SENSOR_DELAY_NORMAL);
        }else{
        	Toast.makeText(getBaseContext(), "Error: No Accelerometer.", Toast.LENGTH_LONG);
        }
    }

	@Override
	protected void onStop() {
		/* Always a good idea to unregister, disconnect, close, etc things */
		if(list.size()>0){
			/* This actually unregisters a listener for all sensors, but it can be done
			   on a sensor by sensor basis */
			sm.unregisterListener(sel);
		}
		super.onStop();
	}

}