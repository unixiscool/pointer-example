{
  description = "C++ project from keng";

  inputs = {
    nixpkgs.url = "https://flakehub.com/f/NixOS/nixpkgs/0.2305.491812.tar.gz";
  };

  outputs = { self, nixpkgs }:
    let
      # Systems supported
      allSystems = [
        "x86_64-linux" # 64-bit Intel/AMD Linux
        "aarch64-linux" # 64-bit ARM Linux
        "x86_64-darwin" # 64-bit Intel macOS
        "aarch64-darwin" # 64-bit ARM macOS
      ];

      # Helper to provide system-specific attributes
      forAllSystems = f: nixpkgs.lib.genAttrs allSystems (system: f {
        pkgs = import nixpkgs { inherit system; };
      });
    in
    {
      packages = forAllSystems ({ pkgs }: {
        default =
          let
            binName = "pointer-example";
            cppDependencies = with pkgs; [ boost gcc poco ];
          in
          pkgs.stdenv.mkDerivation {
            name = "pointer-example";
            src = self;
            buildInputs = cppDependencies;
            buildPhase = "g++ source.cpp header.h function.cpp -o bin";
            installPhase = ''
              mkdir -p $out/bin
              cp bin $out/bin/
            '';
          };
      });
    };
}
