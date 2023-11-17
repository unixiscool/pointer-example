# default.nix

{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
   buildInputs = [pkgs.clang pkgs.emacs ];
}
