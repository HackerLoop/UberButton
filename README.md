# UberButton
ESP8266 button that call a Uber on a preset adress

# How it works

When the button is pressed, a http POST request is sent to AWS API Gateway and trigger a lambda function which call a uber based on preset settings (Start latitude + start longitude + product_id)

To use it you need to create an uber app + get an oauth2 token + identify the product_id of the uber service of your choice in your area
https://developer.uber.com/docs/rides/tutorials-rides-api

Be careful when you test or you'll get cancellation fees :)

# Credits

Inspired by https://github.com/geoffrey/uber-dash-configurator
