package com.logan.dev.ndksampleapp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
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
                String url = txtUrl.getText().toString();

                txtContent.setText(NdkSampleApp.getString(url));
            }
        });

    }
}
