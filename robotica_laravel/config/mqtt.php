<?php
/**
 * Created by PhpStorm.
 * User: salman
 * Date: 2/22/19
 * Time: 1:29 PM
 */

return [

    'host' => env('mqtt_host','postman.cloudmqtt.com'),
    'password' => env('mqtt_password','e6ddQ6ugWipm'),
    'username' => env('mqtt_username','hljnmijh'),
    'certfile' => env('mqtt_cert_file',''),
    'port' => env('mqtt_port','15234'),
    'debug' => env('mqtt_debug',false) //Optional Parameter to enable debugging set it to True
];
