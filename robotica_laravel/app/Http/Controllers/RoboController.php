<?php

namespace App\Http\Controllers;

use Salman\Mqtt\MqttClass\Mqtt;


class RoboController extends Controller
{
    public function index()
    {
        return view("inicio");

        
    }

    public function frente(){
        $message = "3";
        $topic = "robotica";
        $mqtt = new Mqtt();
        $output = $mqtt->ConnectAndPublish($topic, $message);
        return view("inicio");
    }

    public function tras(){
        $message = "2";
        $topic = "robotica";
        $mqtt = new Mqtt();
        $output = $mqtt->ConnectAndPublish($topic, $message);
        return view("inicio");
    }

    public function equilibrar(){
        $message = "3";
        $topic = "robotica";
        $mqtt = new Mqtt();
        $output = $mqtt->ConnectAndPublish($topic, $message);
        return view("inicio");
    }
}
