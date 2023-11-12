{ lib, buildRustPackage, fetchFromGitHub } :

buildRustPackage rec {
  pname = "NixOServerManager";
  version = "0.1.0";

  src = fetchFromGitHub {
    owner = "fullzer4";
    repo = "NixOServerManager";
    rev = "main";
    sha256 = "0gd0ggay4kr8mx5w0r5n67y56q37wh5irzs0agzlrnrcmy4a3dm9";
  };

  meta = with lib; {
    description = "Sua aplicação Rust";
    license = licenses.mit;
  };
}
