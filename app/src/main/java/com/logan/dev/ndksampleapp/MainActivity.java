package com.logan.dev.ndksampleapp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    static {
        System.loadLibrary("NdkSampleApp");
    }

    private EditText txtUrl;
    private Button btnGo;
    private TextView txtContent;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        txtUrl = (EditText) findViewById(R.id.txtUrl);
        btnGo = (Button) findViewById(R.id.btnGo);
        txtContent = (TextView) findViewById(R.id.txtContent);

        btnGo.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                boolean[] booleans = { true, false, false, true };
                booleans = NdkSampleApp.invertBooleans(booleans);

                byte[] bytes = { 22, 2, 32, 12 };
                bytes = NdkSampleApp.sortBytes(bytes);

//                String url = txtUrl.getText().toString();
//                Log.d("NdkSampleApp", "start ndk");
//                txtContent.setText(NdkSampleApp.getHtml(url));


            }
        });

    }
}
