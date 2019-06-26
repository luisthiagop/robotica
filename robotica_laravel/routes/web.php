]<?php

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/

Route::get('/', function () {
    return redirect('/inicio');
});

Route::get('inicio', 'RoboController@index');
Route::get('tras', 'RoboController@tras')->name('tras');
Route::get('frente', 'RoboController@frente')->name('frente');
Route::get('equilibrar', 'RoboController@equilibrar')->name('equilibrar');
