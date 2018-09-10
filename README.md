# Floss Schedule

## About

This is an IoT project that [solves a simple problem](https://gp-floss-schedule.herokuapp.com/): I do not have a way to track my flossing date, time, and duration.

This is my first IoT project. I wanted to have a simple project which was just complex enough to allow for implementing various technologies. The list of used technologies can be found at the end of this document.

## Starting the App

### One-Time Setup

- Install Node and npm
- Global install yarn: `npm install -g yarn`
- Install Heroku CLI: `brew install heroku`
- Copy env file: `cp .env-example .env`
- Enable linting in Sublime Text 3
  - Install `SublimeLinter`
  - Install `SublimeLinter-eslint`
  - Install `SublimeLinter-flow`
- Enable auto-styling in Sublime Text 3
  - Install `JsPrettier`
  - In Terminal, run `which prettier`
  - In Terminal, run `which node`
  - Sublime Text > Preferences > Package Settings > JsPrettier > Settings - User

```json
{
  "prettier_cli_path": "<result of `which prettier`>",
  "node_path": "<result of `which node`>",
  "auto_format_on_save": true,
  "prettier_options": {
    "parser": "babylon",
    "singleQuote": true,
    "printWidth": 80,
    "trailingComma": "es5",
    "bracketSpacing": true,
    "jsxBracketSameLine": false,
    "semi": false,
    "tabs": false
  }
}
```

### Every Time

- Install dependencies: `yarn install`
- Start server: `yarn watch:server`

## Tech Used

- Hardware
  - [Particle Photon](https://www.particle.io/products/hardware/photon-wifi/)
  - LED
  - Photoresistor
- Firmware
  - Particle Build
- Software
  - Node
  - Express

## TODOs

- MVP functionality

## Bonus TODOs

- WebSockets
- PWA
