local serverities = {
  error = vim.diagnostic.serverity.ERROR,
  warning = vim.diagnostic.serverity.WARN,
}

local pattern = "[^:]+:(%d+): (%w+): (.*)"
local groups = { "lnum", "serverity", "message" }

return {
  cmd = "betty-doc",
  stdin = false,
  ignore_exitcode = true,
  stream = "stderr",
  parser = require("lint.parser").from_pattern(pattern, groups, serverities, {
    source = "betty-doc",
  }),
}
