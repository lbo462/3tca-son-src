# 3TCA Projet SON : Sources

Léo BONNAIRE, Léonard PRINCE, Gausse DONGMO

## How to clone

First thing is to install git on your desktop.

### - Configure git

First thing needed is to create a set of SSH keys to access this repo.

See tutorial here : [https://docs.github.com/fr/authentication/connecting-to-github-with-ssh](https://docs.github.com/fr/authentication/connecting-to-github-with-ssh)

Then add your public key to your profile.

Configure your name and email address with :

```shell
git config --global user.name=<name>
git config --global user.email=<email>
```

### - Clone repo 

On a machine with git pre-installed,

```shell
git clone git@github.com:leoNord462/3tca-son-src.git
```

With above configuration, you should be able to read and write in this repo.

## Electrical circuit

Current circuit is a row of 3 buttons linked to a single analogical output (A0).

The resistances we use are 320, 450 and 230 Ohms.