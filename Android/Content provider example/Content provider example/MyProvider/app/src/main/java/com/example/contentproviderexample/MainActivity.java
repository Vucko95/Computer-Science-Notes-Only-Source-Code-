package com.example.contentproviderexample;

import android.app.Activity;
import android.content.ContentValues;
import android.net.Uri;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.activity_main, menu);
		return true;
	}

	public void onClickAddName(View view) {

		ContentValues values = new ContentValues();

		values.put(MyProvider.name, ((EditText) findViewById(R.id.txtName))
				.getText().toString());

		Uri uri = getContentResolver().insert(MyProvider.CONTENT_URI, values);

		Toast.makeText(getBaseContext(), "New record inserted", Toast.LENGTH_LONG)
				.show();
	}
}
