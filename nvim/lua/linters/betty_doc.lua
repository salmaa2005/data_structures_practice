local severities = {
  error = vim.diagnostic.severity.ERROR,
  warning = vim.diagnostic.severity.WARN,
}

local pattern = "[^:]+:(%d+): (%w+): (.*)"
local groups = { "lnum", "severity", "message" }

return {
  cmd = "betty-doc",
  stdin = false,
  ignore_exitcode = true,
  stream = "stderr",
  parser = require("lint.parser").from_pattern(pattern, groups, severities, {
    source = "betty-doc",
  }),
}
