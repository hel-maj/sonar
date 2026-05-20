/* ===== 23e2d0320 ui.home_tab:429 ===== */
/* ghidra_name=FUN_23e2d0320 entry=23e2d0320 size=23878 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

code * FUN_23e2d0320(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  int iVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong lVar12;
  longlong *plVar13;
  longlong lVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  code *pcVar18;
  longlong *plVar19;
  code *pcVar20;
  code *pcVar21;
  longlong *plVar22;
  undefined4 uVar23;
  int iVar24;
  code *pcVar25;
  longlong *local_160;
  longlong *local_158;
  longlong *local_150;
  code *local_148;
  code *local_140;
  code *local_138;
  longlong *local_130;
  undefined1 local_f8 [16];
  code *local_e8;
  code *local_d8;
  code *pcStack_d0;
  code *local_c8;
  longlong *local_b8;
  undefined8 uStack_b0;
  code *local_a8;
  code *pcStack_a0;
  undefined8 local_98;
  undefined1 local_88 [16];
  code *local_78;
  undefined8 local_70;
  undefined8 local_68;
  
  plVar11 = _DAT_23eeb02a0;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eeb02a0 == (longlong *)0x0) {
LAB_23e2d0365:
    _DAT_23eeb02a0 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeb0298,DAT_23eeb0380,0x48);
  }
  else {
    lVar12 = *_DAT_23eeb02a0;
    if (1 < lVar12) {
      *_DAT_23eeb02a0 = lVar12 + -1;
      goto LAB_23e2d0365;
    }
    if (_DAT_23eeb02a0[2] != 0) {
      *_DAT_23eeb02a0 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      goto LAB_23e2d0365;
    }
  }
  plVar3 = _DAT_23eeb02a0;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar11 = _DAT_23eeb02a0 + 9;
  lVar14 = *(longlong *)(lVar12 + 8);
  _DAT_23eeb02a0[0xf] = lVar14;
  *(longlong **)(lVar12 + 8) = plVar11;
  if ((lVar14 != 0) &&
     (((*(char *)(lVar14 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar14 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar14 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar14 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar14 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar5 = _DAT_23eeada98;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,uVar5);
  plVar11 = (longlong *)0x0;
  if (plVar9 == (longlong *)0x0) {
LAB_23e2d08c0:
    local_140 = *(code **)(param_1 + 0x60);
    pcVar21 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    local_148 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcVar21 == (code *)0x0) {
      plVar13 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      local_150 = (longlong *)0x0;
      iVar8 = 0x1af;
      local_158 = (longlong *)0x0;
      local_160 = (longlong *)0x0;
      local_138 = _PyRuntime_exref;
      goto LAB_23e2d1fb0;
    }
    if (plVar3 != *(longlong **)(pcVar21 + 0x18)) {
      plVar13 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      local_150 = (longlong *)0x0;
      iVar24 = 0x1af;
      local_158 = (longlong *)0x0;
      local_160 = (longlong *)0x0;
      local_138 = _PyRuntime_exref;
      goto LAB_23e2d0940;
    }
    goto LAB_23e2d0e70;
  }
  *(undefined4 *)(plVar3 + 5) = 0x1af;
  plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar9,DAT_23eeadf88);
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
    if (plVar10 != (longlong *)0x0) goto LAB_23e2d0432;
LAB_23e2d077b:
    local_140 = *(code **)(param_1 + 0x60);
    pcVar21 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    local_148 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcVar21 == (code *)0x0) {
      plVar9 = (longlong *)0x0;
      goto LAB_23e2d2319;
    }
    if (plVar3 == *(longlong **)(pcVar21 + 0x18)) {
      plVar13 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      local_150 = (longlong *)0x0;
      local_158 = (longlong *)0x0;
      local_160 = (longlong *)0x0;
      pcVar18 = pcVar21;
      goto LAB_23e2d09e0;
    }
    plVar9 = (longlong *)0x0;
LAB_23e2d07db:
    local_150 = (longlong *)0x0;
    local_158 = (longlong *)0x0;
    local_160 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    iVar24 = 0x1af;
    local_138 = _PyRuntime_exref;
  }
  else {
    if (plVar10 == (longlong *)0x0) goto LAB_23e2d077b;
LAB_23e2d0432:
    plVar9 = (longlong *)FUN_23e8bc2f0(plVar10,_DAT_23eeadf90);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
      if (plVar9 != (longlong *)0x0) goto LAB_23e2d0457;
LAB_23e2d0813:
      local_140 = *(code **)(param_1 + 0x60);
      pcVar21 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_148 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (pcVar21 == (code *)0x0) {
        plVar10 = (longlong *)0x0;
LAB_23e2d2319:
        local_150 = (longlong *)0x0;
        local_158 = (longlong *)0x0;
        local_160 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        iVar8 = 0x1af;
        local_138 = _PyRuntime_exref;
LAB_23e2d1fb0:
        pcVar18 = DAT_23ed6a4f8;
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar21 = *(code **)DAT_23ed6a4f8;
          *(undefined8 *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar21;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        *(longlong *)(pcVar18 + 0x10) = 0;
        *(longlong **)(pcVar18 + 0x18) = plVar3;
        *plVar3 = *plVar3 + 1;
        lVar12 = *(longlong *)(local_138 + 0x1f8);
        *(int *)(pcVar18 + 0x24) = iVar8;
        lVar12 = *(longlong *)(lVar12 + 0x10);
        *(undefined4 *)(pcVar18 + 0x20) = 0xffffffff;
        lVar12 = *(longlong *)(lVar12 + 0x2e8);
        lVar14 = *(longlong *)(pcVar18 + -8);
        plVar19 = *(longlong **)(lVar12 + 8);
        *plVar19 = (longlong)(pcVar18 + -0x10);
        *(longlong *)(pcVar18 + -0x10) = lVar12;
        *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar14 & 3) | (ulonglong)plVar19;
        *(code **)(lVar12 + 8) = pcVar18 + -0x10;
        goto LAB_23e2d09e0;
      }
      if (plVar3 == *(longlong **)(pcVar21 + 0x18)) {
        plVar13 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        local_150 = (longlong *)0x0;
        local_158 = (longlong *)0x0;
        local_160 = (longlong *)0x0;
        pcVar18 = pcVar21;
        goto LAB_23e2d09e0;
      }
      plVar10 = (longlong *)0x0;
      goto LAB_23e2d07db;
    }
    if (plVar9 == (longlong *)0x0) goto LAB_23e2d0813;
LAB_23e2d0457:
    *(undefined4 *)(plVar3 + 5) = 0x1af;
    plVar11 = (longlong *)FUN_23e91a870(param_1,plVar9);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    if (plVar11 == (longlong *)0x0) goto LAB_23e2d08c0;
    iVar8 = FUN_23a35f020(plVar11);
    if (iVar8 == -1) {
      local_140 = *(code **)(param_1 + 0x60);
      pcVar21 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_148 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (pcVar21 != (code *)0x0) {
        if (*(longlong **)(pcVar21 + 0x18) != plVar3) {
          plVar13 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          local_150 = (longlong *)0x0;
          iVar24 = 0x1b1;
          local_158 = (longlong *)0x0;
          local_160 = (longlong *)0x0;
          local_138 = _PyRuntime_exref;
          goto LAB_23e2d0940;
        }
        goto LAB_23e2d0e70;
      }
      plVar13 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      local_150 = (longlong *)0x0;
      iVar8 = 0x1b1;
      local_158 = (longlong *)0x0;
      local_160 = (longlong *)0x0;
      local_138 = _PyRuntime_exref;
      goto LAB_23e2d1fb0;
    }
    if (iVar8 != 0) {
      plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eead900);
      if (plVar9 == (longlong *)0x0) {
        local_140 = *(code **)(param_1 + 0x60);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        local_148 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (pcVar21 != (code *)0x0) {
          plVar10 = (longlong *)0x0;
          if (*(longlong **)(pcVar21 + 0x18) == plVar3) goto LAB_23e2d1f40;
          plVar13 = (longlong *)0x0;
          local_150 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          local_158 = (longlong *)0x0;
          iVar24 = 0x1b6;
          local_160 = (longlong *)0x0;
          local_138 = _PyRuntime_exref;
          plVar10 = (longlong *)0x0;
          goto LAB_23e2d0940;
        }
        plVar13 = (longlong *)0x0;
        local_150 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        local_158 = (longlong *)0x0;
        iVar8 = 0x1b6;
        local_160 = (longlong *)0x0;
        local_138 = _PyRuntime_exref;
        plVar10 = (longlong *)0x0;
        goto LAB_23e2d1fb0;
      }
      plVar10 = (longlong *)FUN_23e8bc2f0(plVar9,_DAT_23eeadd18);
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      if (plVar10 == (longlong *)0x0) {
        local_140 = *(code **)(param_1 + 0x60);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        local_148 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (pcVar21 != (code *)0x0) {
          if (*(longlong **)(pcVar21 + 0x18) == plVar3) goto LAB_23e2d20e0;
LAB_23e2d20b9:
          plVar9 = (longlong *)0x0;
          local_150 = (longlong *)0x0;
          local_158 = (longlong *)0x0;
          local_160 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          iVar24 = 0x1b6;
          local_138 = _PyRuntime_exref;
          goto LAB_23e2d0940;
        }
      }
      else {
        iVar8 = FUN_23a35f020(plVar10);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (iVar8 != -1) {
          if (iVar8 == 0) {
            plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeadb40);
            lVar12 = _DAT_23eeadfa0;
            if (plVar9 == (longlong *)0x0) {
              local_140 = *(code **)(param_1 + 0x60);
              pcVar21 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              local_148 = *(code **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (pcVar21 == (code *)0x0) {
                plVar13 = (longlong *)0x0;
                local_150 = (longlong *)0x0;
                plVar9 = (longlong *)0x0;
                local_158 = (longlong *)0x0;
                local_160 = (longlong *)0x0;
                local_138 = _PyRuntime_exref;
                plVar10 = (longlong *)0x0;
                iVar8 = 0x1b7;
                goto LAB_23e2d1fb0;
              }
              plVar10 = (longlong *)0x0;
              if (plVar3 == *(longlong **)(pcVar21 + 0x18)) goto LAB_23e2d1f40;
              plVar13 = (longlong *)0x0;
              local_150 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              local_158 = (longlong *)0x0;
              iVar24 = 0x1b7;
              local_160 = (longlong *)0x0;
              local_138 = _PyRuntime_exref;
              plVar10 = (longlong *)0x0;
            }
            else {
              *(undefined4 *)(plVar3 + 5) = 0x1b7;
              plVar10 = (longlong *)
                        FUN_23e915840(param_1,plVar9,_DAT_23eeada60,*(undefined8 *)(lVar12 + 0x18));
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              if (plVar10 == (longlong *)0x0) {
                local_140 = *(code **)(param_1 + 0x60);
                pcVar21 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                local_148 = *(code **)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (pcVar21 == (code *)0x0) {
                  plVar13 = (longlong *)0x0;
                  plVar10 = (longlong *)0x0;
                  local_150 = (longlong *)0x0;
                  local_158 = (longlong *)0x0;
                  local_160 = (longlong *)0x0;
                  local_138 = _PyRuntime_exref;
                  plVar9 = (longlong *)0x0;
                  iVar8 = 0x1b7;
                  goto LAB_23e2d1fb0;
                }
                if (*(longlong **)(pcVar21 + 0x18) == plVar3) goto LAB_23e2d20e0;
                plVar13 = (longlong *)0x0;
                local_150 = (longlong *)0x0;
                plVar10 = (longlong *)0x0;
                local_158 = (longlong *)0x0;
                iVar24 = 0x1b7;
                local_160 = (longlong *)0x0;
                local_138 = _PyRuntime_exref;
                plVar9 = (longlong *)0x0;
              }
              else {
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeadb40);
                if (plVar9 == (longlong *)0x0) {
                  local_140 = *(code **)(param_1 + 0x60);
                  pcVar21 = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  local_148 = *(code **)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  if (pcVar21 == (code *)0x0) {
                    plVar13 = (longlong *)0x0;
                    local_150 = (longlong *)0x0;
                    plVar9 = (longlong *)0x0;
                    local_158 = (longlong *)0x0;
                    local_160 = (longlong *)0x0;
                    local_138 = _PyRuntime_exref;
                    plVar10 = (longlong *)0x0;
                    iVar8 = 0x1b8;
                    goto LAB_23e2d1fb0;
                  }
                  plVar10 = (longlong *)0x0;
                  if (*(longlong **)(pcVar21 + 0x18) == plVar3) goto LAB_23e2d1f40;
                  plVar13 = (longlong *)0x0;
                  local_150 = (longlong *)0x0;
                  plVar9 = (longlong *)0x0;
                  local_158 = (longlong *)0x0;
                  iVar24 = 0x1b8;
                  local_160 = (longlong *)0x0;
                  local_138 = _PyRuntime_exref;
                  plVar10 = (longlong *)0x0;
                }
                else {
                  plVar13 = (longlong *)FUN_23e8bc2f0(plVar9,_DAT_23eead9b8);
                  *plVar9 = *plVar9 + -1;
                  if (*plVar9 == 0) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
                  plVar9 = _DAT_23eeadb48;
                  if (plVar13 == (longlong *)0x0) {
                    local_140 = *(code **)(param_1 + 0x60);
                    pcVar21 = *(code **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_148 = *(code **)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    if (pcVar21 == (code *)0x0) {
                      plVar13 = (longlong *)0x0;
                      local_150 = (longlong *)0x0;
                      plVar10 = (longlong *)0x0;
                      local_158 = (longlong *)0x0;
                      local_160 = (longlong *)0x0;
                      local_138 = _PyRuntime_exref;
                      plVar9 = (longlong *)0x0;
                      iVar8 = 0x1b8;
                      goto LAB_23e2d1fb0;
                    }
                    if (*(longlong **)(pcVar21 + 0x18) == plVar3) goto LAB_23e2d20e0;
                    plVar13 = (longlong *)0x0;
                    local_150 = (longlong *)0x0;
                    plVar10 = (longlong *)0x0;
                    local_158 = (longlong *)0x0;
                    iVar24 = 0x1b8;
                    local_160 = (longlong *)0x0;
                    local_138 = _PyRuntime_exref;
                    plVar9 = (longlong *)0x0;
                  }
                  else {
                    lVar12 = *(longlong *)(param_1 + 0x10);
                    plVar10 = *(longlong **)(lVar12 + 0xe28);
                    if (plVar10 == (longlong *)0x0) {
                      plVar10 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                    }
                    else {
                      lVar14 = plVar10[3];
                      *(int *)(lVar12 + 0xec0) = *(int *)(lVar12 + 0xec0) + -1;
                      *(longlong *)(lVar12 + 0xe28) = lVar14;
                      *plVar10 = 1;
                    }
                    local_138 = _PyRuntime_exref;
                    *(undefined1 (*) [16])(plVar10 + 4) = (undefined1  [16])0x0;
                    lVar12 = *(longlong *)
                              (*(longlong *)(*(longlong *)(local_138 + 0x1f8) + 0x10) + 0x2e8);
                    lVar14 = plVar10[-1];
                    puVar2 = *(undefined8 **)(lVar12 + 8);
                    *puVar2 = plVar10 + -2;
                    plVar10[-2] = lVar12;
                    plVar10[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar2;
                    *(longlong **)(lVar12 + 8) = plVar10 + -2;
                    *plVar9 = *plVar9 + 1;
                    plVar10[3] = (longlong)plVar9;
                    lVar12 = FUN_23e8f6530();
                    uVar5 = DAT_23ed6cd28;
                    if (lVar12 == 0) {
                      FUN_23e915740(param_1,&local_d8,DAT_23eeadd28);
                      local_140 = local_d8;
                      local_148 = pcStack_d0;
                      pcVar21 = local_c8;
LAB_23e2d2752:
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      *plVar10 = *plVar10 + -1;
                      if (*plVar10 == 0) {
                        (**(code **)(plVar10[1] + 0x30))(plVar10);
                        if (pcVar21 != (code *)0x0) {
                          if (plVar3 == *(longlong **)(pcVar21 + 0x18)) goto LAB_23e2d0e70;
LAB_23e2d279d:
                          plVar13 = (longlong *)0x0;
                          plVar9 = (longlong *)0x0;
                          plVar10 = (longlong *)0x0;
                          local_150 = (longlong *)0x0;
                          iVar24 = 0x1b8;
                          local_158 = (longlong *)0x0;
                          local_160 = (longlong *)0x0;
                          goto LAB_23e2d0940;
                        }
                      }
                      else if (pcVar21 != (code *)0x0) {
                        if (*(longlong **)(pcVar21 + 0x18) != plVar3) goto LAB_23e2d279d;
LAB_23e2d0e70:
                        plVar13 = (longlong *)0x0;
                        plVar9 = (longlong *)0x0;
                        plVar10 = (longlong *)0x0;
                        local_150 = (longlong *)0x0;
                        local_158 = (longlong *)0x0;
                        local_160 = (longlong *)0x0;
                        pcVar18 = pcVar21;
                        goto LAB_23e2d09e0;
                      }
                      plVar13 = (longlong *)0x0;
                      plVar9 = (longlong *)0x0;
                      plVar10 = (longlong *)0x0;
                      local_150 = (longlong *)0x0;
                      local_158 = (longlong *)0x0;
                      local_160 = (longlong *)0x0;
                      iVar8 = 0x1b8;
                      goto LAB_23e2d1fb0;
                    }
                    if (DAT_23ed6a4c0 == (longlong *)0x0) {
                      plVar9 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                      if (plVar9 != (longlong *)0x0) {
                        *plVar9 = *plVar9 + 1;
                        DAT_23ed6a4c0 = plVar9;
                        goto LAB_23e2d0d89;
                      }
LAB_23e2d4214:
                      PyErr_PrintEx(0,0);
                      Py_Exit(1);
                    }
                    else {
LAB_23e2d0d89:
                      local_88._8_8_ = uVar5;
                      local_88._0_8_ = lVar12;
                      lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,local_88);
                      if (lVar12 == 0) {
                        local_140 = *(code **)(param_1 + 0x60);
                        pcVar21 = *(code **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        local_148 = *(code **)(param_1 + 0x68);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        goto LAB_23e2d2752;
                      }
                      plVar10[4] = lVar12;
                      plVar9 = _DAT_23eeadb58;
                      *_DAT_23eeadb58 = *_DAT_23eeadb58 + 1;
                      plVar10[5] = (longlong)plVar9;
                      plVar9 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar10);
                      *plVar10 = *plVar10 + -1;
                      if (*plVar10 == 0) {
                        (**(code **)(plVar10[1] + 0x30))();
                      }
                      if (plVar9 == (longlong *)0x0) {
                        local_140 = *(code **)(param_1 + 0x60);
                        pcVar21 = *(code **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        local_148 = *(code **)(param_1 + 0x68);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *plVar13 = *plVar13 + -1;
                        if (*plVar13 == 0) {
                          (**(code **)(plVar13[1] + 0x30))();
                        }
                        if (pcVar21 == (code *)0x0) {
                          plVar9 = (longlong *)0x0;
                          local_150 = (longlong *)0x0;
                          local_158 = (longlong *)0x0;
                          local_160 = (longlong *)0x0;
                          plVar13 = (longlong *)0x0;
                          plVar10 = (longlong *)0x0;
                          iVar8 = 0x1b8;
                          goto LAB_23e2d1fb0;
                        }
                        if (*(longlong **)(pcVar21 + 0x18) == plVar3) goto LAB_23e2d2a01;
                        plVar9 = (longlong *)0x0;
                        plVar10 = (longlong *)0x0;
                        local_150 = (longlong *)0x0;
                        local_158 = (longlong *)0x0;
                        iVar24 = 0x1b8;
                        local_160 = (longlong *)0x0;
                        plVar13 = (longlong *)0x0;
                        goto LAB_23e2d0940;
                      }
                      *(undefined4 *)(plVar3 + 5) = 0x1b8;
                      plVar19 = (longlong *)FUN_23e914090(param_1,plVar13,plVar9);
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      *plVar9 = *plVar9 + -1;
                      if (*plVar9 == 0) {
                        (**(code **)(plVar9[1] + 0x30))(plVar9);
                      }
                      plVar10 = (longlong *)0x0;
                      if (plVar19 != (longlong *)0x0) {
                        *plVar19 = *plVar19 + -1;
                        if (*plVar19 == 0) {
                          (**(code **)(plVar19[1] + 0x30))(plVar19);
                        }
                        goto LAB_23e2d06bd;
                      }
                    }
                    local_140 = *(code **)(param_1 + 0x60);
                    pcVar21 = *(code **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_148 = *(code **)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    if (pcVar21 == (code *)0x0) {
                      plVar13 = (longlong *)0x0;
                      plVar9 = (longlong *)0x0;
                      local_150 = (longlong *)0x0;
                      local_158 = (longlong *)0x0;
                      local_160 = (longlong *)0x0;
                      iVar8 = 0x1b8;
                      goto LAB_23e2d1fb0;
                    }
                    if (*(longlong **)(pcVar21 + 0x18) == plVar3) goto LAB_23e2d1f40;
                    local_150 = (longlong *)0x0;
                    plVar13 = (longlong *)0x0;
                    plVar9 = (longlong *)0x0;
                    local_158 = (longlong *)0x0;
                    iVar24 = 0x1b8;
                    local_160 = (longlong *)0x0;
                  }
                }
              }
            }
          }
          else {
            plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeadaf8);
            lVar12 = _DAT_23eeadfb0;
            if (plVar9 == (longlong *)0x0) {
              local_140 = *(code **)(param_1 + 0x60);
              pcVar21 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              local_148 = *(code **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (pcVar21 == (code *)0x0) {
                plVar13 = (longlong *)0x0;
                local_150 = (longlong *)0x0;
                plVar9 = (longlong *)0x0;
                local_158 = (longlong *)0x0;
                iVar8 = 0x1bc;
                local_160 = (longlong *)0x0;
                local_138 = _PyRuntime_exref;
                plVar10 = (longlong *)0x0;
                goto LAB_23e2d1fb0;
              }
              plVar10 = (longlong *)0x0;
              if (*(longlong **)(pcVar21 + 0x18) == plVar3) goto LAB_23e2d1f40;
              plVar13 = (longlong *)0x0;
              local_150 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              local_158 = (longlong *)0x0;
              iVar24 = 0x1bc;
              local_160 = (longlong *)0x0;
              local_138 = _PyRuntime_exref;
              plVar10 = (longlong *)0x0;
            }
            else {
              *(undefined4 *)(plVar3 + 5) = 0x1bc;
              plVar10 = (longlong *)
                        FUN_23e915840(param_1,plVar9,_DAT_23eeadfa8,*(undefined8 *)(lVar12 + 0x18));
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              if (plVar10 == (longlong *)0x0) {
                local_140 = *(code **)(param_1 + 0x60);
                pcVar21 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                local_148 = *(code **)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (pcVar21 == (code *)0x0) {
                  plVar13 = (longlong *)0x0;
                  plVar10 = (longlong *)0x0;
                  local_150 = (longlong *)0x0;
                  iVar8 = 0x1bc;
                  local_158 = (longlong *)0x0;
                  local_160 = (longlong *)0x0;
                  local_138 = _PyRuntime_exref;
                  plVar9 = (longlong *)0x0;
                  goto LAB_23e2d1fb0;
                }
                if (*(longlong **)(pcVar21 + 0x18) == plVar3) goto LAB_23e2d20e0;
                plVar13 = (longlong *)0x0;
                local_150 = (longlong *)0x0;
                plVar10 = (longlong *)0x0;
                local_158 = (longlong *)0x0;
                iVar24 = 0x1bc;
                local_160 = (longlong *)0x0;
                local_138 = _PyRuntime_exref;
                plVar9 = (longlong *)0x0;
              }
              else {
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeadb40);
                if (plVar9 == (longlong *)0x0) {
                  local_140 = *(code **)(param_1 + 0x60);
                  pcVar21 = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  local_148 = *(code **)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  if (pcVar21 == (code *)0x0) {
                    plVar13 = (longlong *)0x0;
                    local_150 = (longlong *)0x0;
                    plVar9 = (longlong *)0x0;
                    local_158 = (longlong *)0x0;
                    iVar8 = 0x1bd;
                    local_160 = (longlong *)0x0;
                    local_138 = _PyRuntime_exref;
                    plVar10 = (longlong *)0x0;
                    goto LAB_23e2d1fb0;
                  }
                  plVar10 = (longlong *)0x0;
                  if (plVar3 == *(longlong **)(pcVar21 + 0x18)) goto LAB_23e2d1f40;
                  plVar13 = (longlong *)0x0;
                  local_150 = (longlong *)0x0;
                  plVar9 = (longlong *)0x0;
                  local_158 = (longlong *)0x0;
                  iVar24 = 0x1bd;
                  local_160 = (longlong *)0x0;
                  local_138 = _PyRuntime_exref;
                  plVar10 = (longlong *)0x0;
                }
                else {
                  *(undefined4 *)(plVar3 + 5) = 0x1bd;
                  plVar10 = (longlong *)FUN_23e915840(param_1,plVar9,_DAT_23eeada60);
                  *plVar9 = *plVar9 + -1;
                  if (*plVar9 == 0) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
                  if (plVar10 == (longlong *)0x0) {
                    local_140 = *(code **)(param_1 + 0x60);
                    pcVar21 = *(code **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_148 = *(code **)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    if (pcVar21 == (code *)0x0) {
                      plVar13 = (longlong *)0x0;
                      plVar10 = (longlong *)0x0;
                      local_150 = (longlong *)0x0;
                      iVar8 = 0x1bd;
                      local_158 = (longlong *)0x0;
                      local_160 = (longlong *)0x0;
                      local_138 = _PyRuntime_exref;
                      plVar9 = (longlong *)0x0;
                      goto LAB_23e2d1fb0;
                    }
                    if (*(longlong **)(pcVar21 + 0x18) == plVar3) goto LAB_23e2d20e0;
                    plVar13 = (longlong *)0x0;
                    local_150 = (longlong *)0x0;
                    plVar10 = (longlong *)0x0;
                    local_158 = (longlong *)0x0;
                    iVar24 = 0x1bd;
                    local_160 = (longlong *)0x0;
                    local_138 = _PyRuntime_exref;
                    plVar9 = (longlong *)0x0;
                  }
                  else {
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      (**(code **)(plVar10[1] + 0x30))(plVar10);
                    }
                    plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeadb40);
                    if (plVar10 == (longlong *)0x0) {
                      local_140 = *(code **)(param_1 + 0x60);
                      pcVar21 = *(code **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_148 = *(code **)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      if (pcVar21 == (code *)0x0) {
                        plVar13 = (longlong *)0x0;
                        local_150 = (longlong *)0x0;
                        plVar9 = (longlong *)0x0;
                        local_158 = (longlong *)0x0;
                        iVar8 = 0x1be;
                        local_160 = (longlong *)0x0;
                        local_138 = _PyRuntime_exref;
                        goto LAB_23e2d1fb0;
                      }
                      if (plVar3 == *(longlong **)(pcVar21 + 0x18)) goto LAB_23e2d1f40;
                      plVar13 = (longlong *)0x0;
                      local_150 = (longlong *)0x0;
                      plVar9 = (longlong *)0x0;
                      local_158 = (longlong *)0x0;
                      iVar24 = 0x1be;
                      local_160 = (longlong *)0x0;
                      local_138 = _PyRuntime_exref;
                    }
                    else {
                      plVar9 = (longlong *)FUN_23e8bc2f0(plVar10,_DAT_23eead9b8);
                      *plVar10 = *plVar10 + -1;
                      if (*plVar10 == 0) {
                        (**(code **)(plVar10[1] + 0x30))(plVar10);
                      }
                      plVar13 = _DAT_23eeadb48;
                      if (plVar9 == (longlong *)0x0) {
                        local_140 = *(code **)(param_1 + 0x60);
                        pcVar21 = *(code **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        local_148 = *(code **)(param_1 + 0x68);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        if (pcVar21 == (code *)0x0) {
                          plVar13 = (longlong *)0x0;
                          local_150 = (longlong *)0x0;
                          plVar10 = (longlong *)0x0;
                          local_158 = (longlong *)0x0;
                          iVar8 = 0x1be;
                          local_160 = (longlong *)0x0;
                          local_138 = _PyRuntime_exref;
                          plVar9 = (longlong *)0x0;
                          goto LAB_23e2d1fb0;
                        }
                        if (plVar3 == *(longlong **)(pcVar21 + 0x18)) goto LAB_23e2d20e0;
                        plVar13 = (longlong *)0x0;
                        local_150 = (longlong *)0x0;
                        plVar10 = (longlong *)0x0;
                        local_158 = (longlong *)0x0;
                        iVar24 = 0x1be;
                        local_160 = (longlong *)0x0;
                        local_138 = _PyRuntime_exref;
                        plVar9 = (longlong *)0x0;
                      }
                      else {
                        lVar12 = *(longlong *)(param_1 + 0x10);
                        plVar19 = *(longlong **)(lVar12 + 0xe28);
                        if (plVar19 == (longlong *)0x0) {
                          plVar19 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                        }
                        else {
                          lVar14 = plVar19[3];
                          *(int *)(lVar12 + 0xec0) = *(int *)(lVar12 + 0xec0) + -1;
                          *(longlong *)(lVar12 + 0xe28) = lVar14;
                          *plVar19 = 1;
                        }
                        local_138 = _PyRuntime_exref;
                        *(undefined1 (*) [16])(plVar19 + 4) = (undefined1  [16])0x0;
                        lVar12 = *(longlong *)
                                  (*(longlong *)(*(longlong *)(local_138 + 0x1f8) + 0x10) + 0x2e8);
                        lVar14 = plVar19[-1];
                        puVar2 = *(undefined8 **)(lVar12 + 8);
                        *puVar2 = plVar19 + -2;
                        plVar19[-2] = lVar12;
                        plVar19[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar2;
                        *(longlong **)(lVar12 + 8) = plVar19 + -2;
                        *plVar13 = *plVar13 + 1;
                        plVar19[3] = (longlong)plVar13;
                        lVar12 = FUN_23e8f7100();
                        uVar5 = DAT_23ed6cd28;
                        if (lVar12 == 0) {
                          FUN_23e915740(param_1,&local_d8,DAT_23eeadb50);
                          local_140 = local_d8;
                          local_148 = pcStack_d0;
                          pcVar21 = local_c8;
LAB_23e2d28fb:
                          *plVar9 = *plVar9 + -1;
                          if (*plVar9 == 0) {
                            (**(code **)(plVar9[1] + 0x30))(plVar9);
                          }
                          *plVar19 = *plVar19 + -1;
                          if (*plVar19 == 0) {
                            (**(code **)(plVar19[1] + 0x30))(plVar19);
                            if (pcVar21 == (code *)0x0) {
LAB_23e2d4851:
                              plVar13 = (longlong *)0x0;
                              plVar9 = (longlong *)0x0;
                              plVar10 = (longlong *)0x0;
                              local_150 = (longlong *)0x0;
                              iVar8 = 0x1be;
                              local_158 = (longlong *)0x0;
                              local_160 = (longlong *)0x0;
                              goto LAB_23e2d1fb0;
                            }
                            plVar9 = *(longlong **)(pcVar21 + 0x18);
                          }
                          else {
                            if (pcVar21 == (code *)0x0) goto LAB_23e2d4851;
                            plVar9 = *(longlong **)(pcVar21 + 0x18);
                          }
                          if (plVar3 == plVar9) goto LAB_23e2d0e70;
                        }
                        else {
                          if (DAT_23ed6a4c0 == (longlong *)0x0) {
                            plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                            if (plVar13 == (longlong *)0x0) goto LAB_23e2d4214;
                            *plVar13 = *plVar13 + 1;
                            DAT_23ed6a4c0 = plVar13;
                          }
                          local_88._8_8_ = uVar5;
                          local_88._0_8_ = lVar12;
                          lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,local_88);
                          if (lVar12 == 0) {
                            local_140 = *(code **)(param_1 + 0x60);
                            pcVar21 = *(code **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            local_148 = *(code **)(param_1 + 0x68);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            goto LAB_23e2d28fb;
                          }
                          plVar19[4] = lVar12;
                          plVar13 = _DAT_23eeadb58;
                          *_DAT_23eeadb58 = *_DAT_23eeadb58 + 1;
                          plVar19[5] = (longlong)plVar13;
                          plVar13 = (longlong *)PyUnicode_Join(DAT_23ed6cd28);
                          *plVar19 = *plVar19 + -1;
                          if (*plVar19 == 0) {
                            (**(code **)(plVar19[1] + 0x30))(plVar19);
                          }
                          if (plVar13 == (longlong *)0x0) {
                            local_140 = *(code **)(param_1 + 0x60);
                            pcVar21 = *(code **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            local_148 = *(code **)(param_1 + 0x68);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *plVar9 = *plVar9 + -1;
                            if (*plVar9 == 0) {
                              (**(code **)(plVar9[1] + 0x30))(plVar9);
                            }
                            if (pcVar21 != (code *)0x0) {
                              if (plVar3 == *(longlong **)(pcVar21 + 0x18)) goto LAB_23e2d2a01;
                              plVar9 = (longlong *)0x0;
                              plVar10 = (longlong *)0x0;
                              local_150 = (longlong *)0x0;
                              local_158 = (longlong *)0x0;
                              iVar24 = 0x1be;
                              local_160 = (longlong *)0x0;
                              plVar13 = (longlong *)0x0;
                              goto LAB_23e2d0940;
                            }
                            plVar9 = (longlong *)0x0;
                            iVar8 = 0x1be;
                            local_150 = (longlong *)0x0;
                            local_158 = (longlong *)0x0;
                            local_160 = (longlong *)0x0;
                            plVar13 = (longlong *)0x0;
                            plVar10 = (longlong *)0x0;
                            goto LAB_23e2d1fb0;
                          }
                          *(undefined4 *)(plVar3 + 5) = 0x1be;
                          plVar19 = (longlong *)FUN_23e914090(param_1,plVar9);
                          *plVar9 = *plVar9 + -1;
                          if (*plVar9 == 0) {
                            (**(code **)(plVar9[1] + 0x30))(plVar9);
                          }
                          *plVar13 = *plVar13 + -1;
                          if (*plVar13 == 0) {
                            (**(code **)(plVar13[1] + 0x30))(plVar13);
                          }
                          if (plVar19 != (longlong *)0x0) {
                            lVar12 = *plVar19;
                            *plVar19 = lVar12 + -1;
                            if (lVar12 + -1 == 0) {
                              (**(code **)(plVar19[1] + 0x30))(plVar19);
                            }
                            local_140 = _Py_NoneStruct_exref;
                            local_b8 = _DAT_23eeade70;
                            *(undefined4 *)(plVar3 + 5) = 0x1c1;
                            local_98 = DAT_23ed6ccf0;
                            uStack_b0 = DAT_23eeae258;
                            local_a8 = local_140;
                            pcStack_a0 = local_140;
                            if (DAT_23ed6a498 == (longlong *)0x0) {
                              plVar9 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"__import__");
                              if (plVar9 == (longlong *)0x0) goto LAB_23e2d4214;
                              *plVar9 = *plVar9 + 1;
                              DAT_23ed6a498 = plVar9;
                            }
                            plVar10 = (longlong *)FUN_23e95b390(param_1,DAT_23ed6a498,&local_b8);
                            uVar6 = _DAT_23eeade80;
                            uVar5 = _DAT_23eeade78;
                            if (plVar10 != (longlong *)0x0) {
                              *(undefined4 *)(plVar3 + 5) = 0x1c2;
                              local_68 = DAT_23ed6ccf0;
                              local_70 = uVar6;
                              local_78 = local_140;
                              local_88._8_8_ = DAT_23eeae258;
                              local_88._0_8_ = uVar5;
                              if (DAT_23ed6a498 == (longlong *)0x0) {
                                plVar9 = (longlong *)
                                         PyDict_GetItemString(DAT_23ed6ccc0,"__import__");
                                if (plVar9 == (longlong *)0x0) goto LAB_23e2d4214;
                                *plVar9 = *plVar9 + 1;
                                DAT_23ed6a498 = plVar9;
                              }
                              plVar13 = (longlong *)FUN_23e95b390(param_1,DAT_23ed6a498,local_88);
                              if (plVar13 == (longlong *)0x0) {
                                pcVar18 = *(code **)(param_1 + 0x60);
                                pcVar20 = *(code **)(param_1 + 0x68);
                                pcVar21 = *(code **)(param_1 + 0x70);
                                plVar9 = (longlong *)0x0;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                uVar23 = 0x1c2;
                                local_150 = (longlong *)0x0;
                                local_158 = (longlong *)0x0;
                                local_160 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plVar13 = (longlong *)0x0;
                                goto LAB_23e2d2b00;
                              }
                              if (((code *)plVar13[1] == PyModule_Type_exref) ||
                                 (iVar8 = PyType_IsSubtype(), uVar5 = _DAT_23eeade88, iVar8 != 0)) {
                                uVar7 = DAT_23eeae258;
                                uVar6 = _DAT_23eeade88;
                                uVar5 = DAT_23ed6ccf0;
                                plVar9 = (longlong *)PyObject_GetAttr(plVar13,_DAT_23eeade88);
                                if (plVar9 == (longlong *)0x0) {
                                  plVar9 = (longlong *)
                                           FUN_23e970390(param_1,plVar13,uVar7,uVar6,uVar5);
                                  goto LAB_23e2d2a9b;
                                }
LAB_23e2d12c9:
                                *plVar13 = *plVar13 + -1;
                                if (*plVar13 == 0) {
                                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                                }
                              }
                              else {
                                plVar9 = (longlong *)PyObject_GetAttr(plVar13,_DAT_23eeade88);
                                if (plVar9 != (longlong *)0x0) goto LAB_23e2d12c9;
                                plVar9 = (longlong *)FUN_23e8d2cf0(param_1,plVar13,uVar5);
LAB_23e2d2a9b:
                                *plVar13 = *plVar13 + -1;
                                if (*plVar13 == 0) {
                                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                                }
                                if (plVar9 == (longlong *)0x0) {
                                  pcVar21 = *(code **)(param_1 + 0x70);
                                  pcVar18 = *(code **)(param_1 + 0x60);
                                  pcVar20 = *(code **)(param_1 + 0x68);
                                  plVar13 = (longlong *)0x0;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  uVar23 = 0x1c2;
                                  local_150 = (longlong *)0x0;
                                  local_158 = (longlong *)0x0;
                                  local_160 = (longlong *)0x0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  goto LAB_23e2d2b00;
                                }
                              }
                              plVar19 = (longlong *)FUN_23e8bc2f0(plVar10,_DAT_23eeadfc0);
                              if (plVar19 == (longlong *)0x0) {
                                pcVar18 = *(code **)(param_1 + 0x60);
                                pcVar20 = *(code **)(param_1 + 0x68);
                                pcVar21 = *(code **)(param_1 + 0x70);
                                plVar13 = (longlong *)0x0;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                uVar23 = 0x1c5;
                                local_150 = (longlong *)0x0;
                                local_158 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                local_160 = (longlong *)0x0;
                                goto LAB_23e2d2b00;
                              }
                              plVar13 = (longlong *)FUN_23e8bc2f0(plVar9,_DAT_23eeade90);
                              uVar5 = DAT_23ed6cd28;
                              if (plVar13 == (longlong *)0x0) {
                                pcVar18 = *(code **)(param_1 + 0x60);
                                pcVar20 = *(code **)(param_1 + 0x68);
                                pcVar21 = *(code **)(param_1 + 0x70);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                lVar12 = *plVar19;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *plVar19 = lVar12 + -1;
                                local_158 = (longlong *)0x0;
                                if (lVar12 + -1 == 0) {
                                  plVar13 = (longlong *)0x0;
                                  FUN_23a334bc0();
                                  uVar23 = 0x1c6;
                                  local_150 = (longlong *)0x0;
                                  local_160 = (longlong *)0x0;
                                }
                                else {
LAB_23e2d4cfb:
                                  local_158 = (longlong *)0x0;
                                  plVar13 = (longlong *)0x0;
                                  uVar23 = 0x1c6;
                                  local_150 = (longlong *)0x0;
                                  local_160 = (longlong *)0x0;
                                }
                                goto LAB_23e2d2b00;
                              }
                              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                plVar15 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                                if (plVar15 == (longlong *)0x0) goto LAB_23e2d4214;
                                *plVar15 = *plVar15 + 1;
                                DAT_23ed6a4c0 = plVar15;
                              }
                              local_88._8_8_ = uVar5;
                              local_88._0_8_ = plVar13;
                              lVar14 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,local_88);
                              lVar12 = *plVar13;
                              *plVar13 = lVar12 + -1;
                              if (lVar12 + -1 == 0) {
                                (**(code **)(plVar13[1] + 0x30))(plVar13);
                              }
                              if (lVar14 == 0) {
                                pcVar21 = *(code **)(param_1 + 0x70);
                                pcVar18 = *(code **)(param_1 + 0x60);
                                pcVar20 = *(code **)(param_1 + 0x68);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                lVar12 = *plVar19;
                                *plVar19 = lVar12 + -1;
                                plVar13 = (longlong *)0x0;
                                if (lVar12 + -1 == 0) {
                                  FUN_23a334bc0(plVar19);
                                  uVar23 = 0x1c6;
                                  local_150 = (longlong *)0x0;
                                  local_158 = (longlong *)0x0;
                                  local_160 = (longlong *)0x0;
                                }
                                else {
                                  local_150 = (longlong *)0x0;
                                  local_158 = (longlong *)0x0;
                                  local_160 = (longlong *)0x0;
                                  uVar23 = 0x1c6;
                                }
                                goto LAB_23e2d2b00;
                              }
                              lVar12 = *(longlong *)(param_1 + 0x10);
                              plVar13 = *(longlong **)(lVar12 + 0xe20);
                              if (plVar13 == (longlong *)0x0) {
                                plVar13 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                              }
                              else {
                                lVar4 = plVar13[3];
                                *(int *)(lVar12 + 0xebc) = *(int *)(lVar12 + 0xebc) + -1;
                                *(longlong *)(lVar12 + 0xe20) = lVar4;
                                *plVar13 = 1;
                              }
                              lVar12 = *(longlong *)
                                        (*(longlong *)(*(longlong *)(local_138 + 0x1f8) + 0x10) +
                                        0x2e8);
                              lVar4 = plVar13[-1];
                              puVar2 = *(undefined8 **)(lVar12 + 8);
                              *puVar2 = plVar13 + -2;
                              plVar15 = _DAT_23eeadfc8;
                              plVar13[-2] = lVar12;
                              plVar13[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar2;
                              *(longlong **)(lVar12 + 8) = plVar13 + -2;
                              plVar13[3] = lVar14;
                              *plVar15 = *plVar15 + 1;
                              plVar13[4] = (longlong)plVar15;
                              plVar15 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar13);
                              *plVar13 = *plVar13 + -1;
                              if (*plVar13 == 0) {
                                (**(code **)(plVar13[1] + 0x30))();
                              }
                              uVar5 = _DAT_23eeadfd0;
                              if (plVar15 == (longlong *)0x0) {
                                pcVar21 = *(code **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                pcVar18 = *(code **)(param_1 + 0x60);
                                pcVar20 = *(code **)(param_1 + 0x68);
                                lVar12 = *plVar19;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *plVar19 = lVar12 + -1;
                                if (lVar12 + -1 == 0) {
                                  FUN_23a334bc0();
                                }
                                goto LAB_23e2d4cfb;
                              }
                              plVar16 = (longlong *)_PyDict_NewPresized(3);
                              PyDict_SetItem(plVar16,uVar5,plVar11);
                              uVar5 = _DAT_23eeadfd8;
                              plVar13 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eead900);
                              if (plVar13 == (longlong *)0x0) {
LAB_23e2d4f59:
                                pcVar18 = *(code **)(param_1 + 0x60);
                                pcVar20 = *(code **)(param_1 + 0x68);
                                pcVar21 = *(code **)(param_1 + 0x70);
                                uVar23 = 0x1c9;
LAB_23e2d4f67:
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                lVar12 = *plVar19;
                                *plVar19 = lVar12 + -1;
                                if (lVar12 + -1 == 0) {
                                  FUN_23a334bc0();
                                }
                                lVar12 = *plVar15;
                                *plVar15 = lVar12 + -1;
                                if (lVar12 + -1 == 0) {
                                  FUN_23a334bc0();
                                }
                                *plVar16 = *plVar16 + -1;
                                if (*plVar16 == 0) {
                                  plVar13 = (longlong *)0x0;
                                  FUN_23a334bc0(plVar16);
                                  local_150 = (longlong *)0x0;
                                  local_158 = (longlong *)0x0;
                                  local_160 = (longlong *)0x0;
                                }
                                else {
                                  plVar13 = (longlong *)0x0;
                                  local_150 = (longlong *)0x0;
                                  local_158 = (longlong *)0x0;
                                  local_160 = (longlong *)0x0;
                                }
                                goto LAB_23e2d2b00;
                              }
                              plVar17 = (longlong *)FUN_23e8bc2f0(plVar13,_DAT_23eeadd18);
                              *plVar13 = *plVar13 + -1;
                              if (*plVar13 == 0) {
                                FUN_23a334bc0();
                              }
                              if (plVar17 == (longlong *)0x0) goto LAB_23e2d4f59;
                              PyDict_SetItem(plVar16,uVar5);
                              *plVar17 = *plVar17 + -1;
                              if (*plVar17 == 0) {
                                FUN_23a334bc0(plVar17);
                              }
                              uVar5 = _DAT_23eeadfe0;
                              plVar13 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eead900);
                              if (plVar13 == (longlong *)0x0) {
LAB_23e2d5213:
                                pcVar18 = *(code **)(param_1 + 0x60);
                                pcVar20 = *(code **)(param_1 + 0x68);
                                pcVar21 = *(code **)(param_1 + 0x70);
                                uVar23 = 0x1ca;
                                goto LAB_23e2d4f67;
                              }
                              plVar17 = (longlong *)FUN_23e8bc2f0(plVar13,_DAT_23eeadfe8);
                              *plVar13 = *plVar13 + -1;
                              if (*plVar13 == 0) {
                                FUN_23a334bc0();
                              }
                              if (plVar17 == (longlong *)0x0) goto LAB_23e2d5213;
                              PyDict_SetItem(plVar16,uVar5);
                              *plVar17 = *plVar17 + -1;
                              if (*plVar17 == 0) {
                                FUN_23a334bc0(plVar17);
                              }
                              local_88._8_8_ = _DAT_23eeadff0;
                              *(undefined4 *)(plVar3 + 5) = 0x1c5;
                              local_88._0_8_ = plVar16;
                              local_b8 = plVar15;
                              plVar13 = (longlong *)
                                        FUN_23e939900(param_1,plVar19,&local_b8,local_88,
                                                      _DAT_23eeadff8);
                              lVar12 = *plVar19;
                              *plVar19 = lVar12 + -1;
                              if (lVar12 + -1 == 0) {
                                FUN_23a334bc0(plVar19);
                              }
                              lVar12 = *plVar15;
                              *plVar15 = lVar12 + -1;
                              if (lVar12 + -1 == 0) {
                                FUN_23a334bc0(plVar15);
                              }
                              *plVar16 = *plVar16 + -1;
                              if (*plVar16 == 0) {
                                FUN_23a334bc0(plVar16);
                              }
                              if (plVar13 == (longlong *)0x0) {
                                pcVar18 = *(code **)(param_1 + 0x60);
                                pcVar20 = *(code **)(param_1 + 0x68);
                                pcVar21 = *(code **)(param_1 + 0x70);
                                local_150 = (longlong *)0x0;
                                uVar23 = 0x1c5;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                local_158 = (longlong *)0x0;
                                local_160 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                goto LAB_23e2d2b00;
                              }
                              plVar19 = (longlong *)FUN_23e8bc2f0(plVar13,_DAT_23eeadeb8);
                              if (plVar19 == (longlong *)0x0) {
                                pcVar18 = *(code **)(param_1 + 0x60);
                                pcVar20 = *(code **)(param_1 + 0x68);
                                pcVar21 = *(code **)(param_1 + 0x70);
                                local_150 = (longlong *)0x0;
                                uVar23 = 0x1cf;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                local_158 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                local_160 = (longlong *)0x0;
                                goto LAB_23e2d2b00;
                              }
                              iVar8 = FUN_23e97a530(plVar19,_DAT_23eeadec0);
                              lVar12 = *plVar19;
                              *plVar19 = lVar12 + -1;
                              if (lVar12 + -1 == 0) {
                                FUN_23a334bc0(plVar19);
                              }
                              if (iVar8 == -1) {
                                pcVar18 = *(code **)(param_1 + 0x60);
                                pcVar20 = *(code **)(param_1 + 0x68);
                                pcVar21 = *(code **)(param_1 + 0x70);
                                local_150 = (longlong *)0x0;
                                uVar23 = 0x1cf;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                local_158 = (longlong *)0x0;
                                local_160 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                goto LAB_23e2d2b00;
                              }
                              if (iVar8 == 1) {
                                *(undefined4 *)(plVar3 + 5) = 0x1d0;
                                local_160 = (longlong *)FUN_23e91bfe0(param_1,plVar13);
                                if (local_160 == (longlong *)0x0) {
                                  pcVar18 = *(code **)(param_1 + 0x60);
                                  pcVar20 = *(code **)(param_1 + 0x68);
                                  pcVar21 = *(code **)(param_1 + 0x70);
                                  local_150 = (longlong *)0x0;
                                  uVar23 = 0x1d0;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  local_158 = (longlong *)0x0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                }
                                else {
                                  plVar19 = (longlong *)FUN_23e8bc2f0(local_160,DAT_23ed6ce40);
                                  if (plVar19 == (longlong *)0x0) {
                                    pcVar18 = *(code **)(param_1 + 0x60);
                                    pcVar20 = *(code **)(param_1 + 0x68);
                                    pcVar21 = *(code **)(param_1 + 0x70);
                                    local_158 = (longlong *)0x0;
                                    uVar23 = 0x1d1;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    local_150 = (longlong *)0x0;
                                  }
                                  else {
                                    *(undefined4 *)(plVar3 + 5) = 0x1d1;
                                    local_158 = (longlong *)
                                                FUN_23e9557e0(param_1,plVar19,_DAT_23eeae000);
                                    lVar12 = *plVar19;
                                    *plVar19 = lVar12 + -1;
                                    if (lVar12 + -1 == 0) {
                                      FUN_23a334bc0();
                                    }
                                    if (local_158 == (longlong *)0x0) {
                                      pcVar18 = *(code **)(param_1 + 0x60);
                                      pcVar20 = *(code **)(param_1 + 0x68);
                                      pcVar21 = *(code **)(param_1 + 0x70);
                                      local_150 = (longlong *)0x0;
                                      uVar23 = 0x1d1;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                    }
                                    else {
                                      plVar19 = (longlong *)FUN_23e8bc2f0(plVar1);
                                      if (plVar19 == (longlong *)0x0) {
                                        pcVar18 = *(code **)(param_1 + 0x60);
                                        pcVar20 = *(code **)(param_1 + 0x68);
                                        pcVar21 = *(code **)(param_1 + 0x70);
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        uVar23 = 0x1d2;
                                        local_150 = (longlong *)0x0;
                                      }
                                      else {
                                        plVar15 = (longlong *)FUN_23e8bc2f0(plVar19,_DAT_23eeada60);
                                        lVar12 = *plVar19;
                                        *plVar19 = lVar12 + -1;
                                        if (lVar12 + -1 == 0) {
                                          FUN_23a334bc0(plVar19);
                                        }
                                        plVar19 = _DAT_23eeae008;
                                        if (plVar15 == (longlong *)0x0) {
LAB_23e2d5d78:
                                          pcVar18 = *(code **)(param_1 + 0x60);
                                          pcVar20 = *(code **)(param_1 + 0x68);
                                          pcVar21 = *(code **)(param_1 + 0x70);
                                          local_150 = (longlong *)0x0;
                                          uVar23 = 0x1d2;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                        }
                                        else {
                                          plVar16 = (longlong *)
                                                    FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2)
                                          ;
                                          *plVar19 = *plVar19 + 1;
                                          plVar16[3] = (longlong)plVar19;
                                          lVar12 = FUN_23e94f9d0(param_1,local_158,DAT_23ed6cd28);
                                          if (lVar12 == 0) {
                                            pcVar18 = *(code **)(param_1 + 0x60);
                                            pcVar20 = *(code **)(param_1 + 0x68);
                                            pcVar21 = *(code **)(param_1 + 0x70);
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            *plVar15 = *plVar15 + -1;
                                            if (*plVar15 == 0) {
                                              FUN_23a334bc0(plVar15);
                                            }
                                            *plVar16 = *plVar16 + -1;
                                            uVar23 = 0x1d2;
                                            local_150 = (longlong *)0x0;
                                            if (*plVar16 == 0) {
                                              FUN_23a334bc0(plVar16);
                                              uVar23 = 0x1d2;
                                            }
                                          }
                                          else {
                                            plVar16[4] = lVar12;
                                            plVar19 = (longlong *)
                                                      PyUnicode_Join(DAT_23ed6cd28,plVar16);
                                            *plVar16 = *plVar16 + -1;
                                            if (*plVar16 == 0) {
                                              FUN_23a334bc0(plVar16);
                                            }
                                            if (plVar19 == (longlong *)0x0) {
                                              pcVar18 = *(code **)(param_1 + 0x60);
                                              pcVar20 = *(code **)(param_1 + 0x68);
                                              pcVar21 = *(code **)(param_1 + 0x70);
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              uVar23 = 0x1d2;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              *plVar15 = *plVar15 + -1;
                                              lVar12 = *plVar15;
joined_r0x00023e2d5bc5:
                                              local_150 = (longlong *)0x0;
                                              if (lVar12 == 0) {
                                                local_150 = (longlong *)0x0;
                                                FUN_23a334bc0(plVar15);
                                              }
                                            }
                                            else {
                                              *(undefined4 *)(plVar3 + 5) = 0x1d2;
                                              plVar16 = (longlong *)
                                                        FUN_23e914090(param_1,plVar15,plVar19);
                                              *plVar15 = *plVar15 + -1;
                                              if (*plVar15 == 0) {
                                                FUN_23a334bc0(plVar15);
                                              }
                                              lVar12 = *plVar19;
                                              *plVar19 = lVar12 + -1;
                                              if (lVar12 + -1 == 0) {
                                                FUN_23a334bc0();
                                              }
                                              if (plVar16 == (longlong *)0x0) goto LAB_23e2d5d78;
                                              *plVar16 = *plVar16 + -1;
                                              if (*plVar16 == 0) {
                                                FUN_23a334bc0(plVar16);
                                              }
                                              plVar19 = (longlong *)
                                                        FUN_23e8bc2f0(plVar1,_DAT_23eeadb40);
                                              if (plVar19 == (longlong *)0x0) {
                                                pcVar18 = *(code **)(param_1 + 0x60);
                                                pcVar20 = *(code **)(param_1 + 0x68);
                                                pcVar21 = *(code **)(param_1 + 0x70);
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                                uVar23 = 0x1d3;
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                local_150 = (longlong *)0x0;
                                              }
                                              else {
                                                plVar15 = (longlong *)
                                                          FUN_23e8bc2f0(plVar19,_DAT_23eead9b8);
                                                lVar12 = *plVar19;
                                                *plVar19 = lVar12 + -1;
                                                if (lVar12 + -1 == 0) {
                                                  FUN_23a334bc0(plVar19);
                                                }
                                                plVar19 = _DAT_23eeadb48;
                                                if (plVar15 == (longlong *)0x0) {
LAB_23e2d5c7b:
                                                  pcVar18 = *(code **)(param_1 + 0x60);
                                                  pcVar20 = *(code **)(param_1 + 0x68);
                                                  pcVar21 = *(code **)(param_1 + 0x70);
                                                  local_150 = (longlong *)0x0;
                                                  uVar23 = 0x1d3;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                }
                                                else {
                                                  plVar16 = (longlong *)
                                                            FUN_23e916ad0(*(undefined8 *)
                                                                           (param_1 + 0x10),3);
                                                  *plVar19 = *plVar19 + 1;
                                                  plVar16[3] = (longlong)plVar19;
                                                  lVar12 = FUN_23e8f6680();
                                                  if (lVar12 == 0) {
                                                    FUN_23e915740(param_1,&local_d8,DAT_23eeadd68);
                                                    pcVar21 = local_c8;
                                                    pcVar18 = local_d8;
                                                    pcVar20 = pcStack_d0;
                                                  }
                                                  else {
                                                    lVar12 = FUN_23e94f9d0(param_1,lVar12,
                                                                           DAT_23ed6cd28);
                                                    if (lVar12 != 0) {
                                                      plVar16[4] = lVar12;
                                                      plVar19 = _DAT_23eeadb58;
                                                      *_DAT_23eeadb58 = *_DAT_23eeadb58 + 1;
                                                      plVar16[5] = (longlong)plVar19;
                                                      plVar19 = (longlong *)
                                                                PyUnicode_Join(DAT_23ed6cd28,plVar16
                                                                              );
                                                      *plVar16 = *plVar16 + -1;
                                                      if (*plVar16 == 0) {
                                                        FUN_23a334bc0(plVar16);
                                                      }
                                                      if (plVar19 == (longlong *)0x0) {
                                                        pcVar18 = *(code **)(param_1 + 0x60);
                                                        pcVar20 = *(code **)(param_1 + 0x68);
                                                        pcVar21 = *(code **)(param_1 + 0x70);
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        uVar23 = 0x1d3;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        *plVar15 = *plVar15 + -1;
                                                        lVar12 = *plVar15;
                                                        goto joined_r0x00023e2d5bc5;
                                                      }
                                                      *(undefined4 *)(plVar3 + 5) = 0x1d3;
                                                      plVar16 = (longlong *)
                                                                FUN_23e914090(param_1,plVar15);
                                                      *plVar15 = *plVar15 + -1;
                                                      if (*plVar15 == 0) {
                                                        FUN_23a334bc0(plVar15);
                                                      }
                                                      lVar12 = *plVar19;
                                                      *plVar19 = lVar12 + -1;
                                                      if (lVar12 + -1 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                      if (plVar16 == (longlong *)0x0)
                                                      goto LAB_23e2d5c7b;
                                                      *plVar16 = *plVar16 + -1;
                                                      if (*plVar16 == 0) {
                                                        FUN_23a334bc0(plVar16);
                                                      }
                                                      local_150 = (longlong *)
                                                                  FUN_23e8bc2f0(plVar1,
                                                  _DAT_23eeada98);
                                                  if (local_150 == (longlong *)0x0) {
LAB_23e2d5b82:
                                                    pcVar18 = *(code **)(param_1 + 0x60);
                                                    pcVar20 = *(code **)(param_1 + 0x68);
                                                    pcVar21 = *(code **)(param_1 + 0x70);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    uVar23 = 0x1d4;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                  }
                                                  else {
                                                    plVar19 = (longlong *)
                                                              FUN_23e8bc2f0(local_150,_DAT_23eeae010
                                                                           );
                                                    lVar12 = *local_150;
                                                    *local_150 = lVar12 + -1;
                                                    if (lVar12 + -1 == 0) {
                                                      FUN_23a334bc0(local_150);
                                                    }
                                                    if (plVar19 == (longlong *)0x0) {
                                                      pcVar18 = *(code **)(param_1 + 0x60);
                                                      pcVar20 = *(code **)(param_1 + 0x68);
                                                      pcVar21 = *(code **)(param_1 + 0x70);
                                                      local_150 = (longlong *)0x0;
                                                      uVar23 = 0x1d4;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                    }
                                                    else {
                                                      *(undefined4 *)(plVar3 + 5) = 0x1d4;
                                                      local_150 = (longlong *)
                                                                  FUN_23e91a870(param_1,plVar19);
                                                      *plVar19 = *plVar19 + -1;
                                                      if (*plVar19 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                      if (local_150 == (longlong *)0x0)
                                                      goto LAB_23e2d5b82;
                                                      lVar12 = *local_150;
                                                      *local_150 = lVar12 + -1;
                                                      if (lVar12 + -1 == 0) {
                                                        FUN_23a334bc0(local_150);
                                                      }
                                                      lVar12 = FUN_23e8f78c0();
                                                      if (lVar12 == 0) {
                                                        FUN_23e915740(param_1,&local_d8,
                                                                      DAT_23eead910);
                                                        uVar23 = 0x1d7;
                                                        local_150 = (longlong *)0x0;
                                                        pcVar21 = local_c8;
                                                        pcVar18 = local_d8;
                                                        pcVar20 = pcStack_d0;
                                                      }
                                                      else {
                                                        plVar15 = (longlong *)
                                                                  FUN_23e8bc2f0(lVar12,
                                                  _DAT_23eeae018);
                                                  uVar5 = _DAT_23eeae020;
                                                  if (plVar15 != (longlong *)0x0) {
                                                    plVar19 = (longlong *)FUN_23e8bc2f0(plVar1);
                                                    if (plVar19 == (longlong *)0x0) {
                                                      pcVar18 = *(code **)(param_1 + 0x60);
                                                      pcVar20 = *(code **)(param_1 + 0x68);
                                                      pcVar21 = *(code **)(param_1 + 0x70);
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      uVar23 = 0x1d7;
                                                      *plVar15 = *plVar15 + -1;
                                                      lVar12 = *plVar15;
                                                      goto joined_r0x00023e2d5bc5;
                                                    }
                                                    *(undefined4 *)(plVar3 + 5) = 0x1d7;
                                                    local_88._8_8_ = plVar19;
                                                    local_88._0_8_ = uVar5;
                                                    plVar16 = (longlong *)
                                                              FUN_23e94ed00(param_1,plVar15,local_88
                                                                           );
                                                    *plVar15 = *plVar15 + -1;
                                                    if (*plVar15 == 0) {
                                                      FUN_23a334bc0(plVar15);
                                                    }
                                                    lVar12 = *plVar19;
                                                    *plVar19 = lVar12 + -1;
                                                    if (lVar12 + -1 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    if (plVar16 != (longlong *)0x0) {
                                                      *plVar16 = *plVar16 + -1;
                                                      local_150 = (longlong *)0x0;
                                                      if (*plVar16 == 0) {
                                                        FUN_23a334bc0(plVar16);
                                                      }
                                                      goto LAB_23e2d1a58;
                                                    }
                                                  }
                                                  pcVar18 = *(code **)(param_1 + 0x60);
                                                  pcVar21 = *(code **)(param_1 + 0x70);
                                                  local_150 = (longlong *)0x0;
                                                  uVar23 = 0x1d7;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  pcVar20 = *(code **)(param_1 + 0x68);
                                                  }
                                                  }
                                                  }
                                                  goto LAB_23e2d2b00;
                                                  }
                                                  pcVar21 = *(code **)(param_1 + 0x70);
                                                  pcVar18 = *(code **)(param_1 + 0x60);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  pcVar20 = *(code **)(param_1 + 0x68);
                                                  }
                                                  *plVar15 = *plVar15 + -1;
                                                  if (*plVar15 == 0) {
                                                    FUN_23a334bc0(plVar15);
                                                  }
                                                  *plVar16 = *plVar16 + -1;
                                                  if (*plVar16 == 0) {
                                                    FUN_23a334bc0(plVar16);
                                                    uVar23 = 0x1d3;
                                                    local_150 = (longlong *)0x0;
                                                  }
                                                  else {
                                                    uVar23 = 0x1d3;
                                                    local_150 = (longlong *)0x0;
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                                goto LAB_23e2d2b00;
                              }
                              *(undefined4 *)(plVar3 + 5) = 0x1d9;
                              plVar19 = (longlong *)FUN_23e91bfe0(param_1,plVar13);
                              if (plVar19 == (longlong *)0x0) {
                                pcVar18 = *(code **)(param_1 + 0x60);
                                pcVar21 = *(code **)(param_1 + 0x70);
                                local_150 = (longlong *)0x0;
                                uVar23 = 0x1d9;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                local_158 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                local_160 = (longlong *)0x0;
                                pcVar20 = *(code **)(param_1 + 0x68);
                                goto LAB_23e2d2b00;
                              }
                              plVar15 = (longlong *)FUN_23e8bc2f0(plVar19,DAT_23ed6ce40);
                              lVar12 = *plVar19;
                              *plVar19 = lVar12 + -1;
                              if (lVar12 + -1 == 0) {
                                FUN_23a334bc0(plVar19);
                              }
                              if (plVar15 == (longlong *)0x0) {
                                pcVar18 = *(code **)(param_1 + 0x60);
                                pcVar21 = *(code **)(param_1 + 0x70);
                                local_150 = (longlong *)0x0;
                                uVar23 = 0x1d9;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                local_160 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                local_158 = (longlong *)0x0;
                                pcVar20 = *(code **)(param_1 + 0x68);
                                goto LAB_23e2d2b00;
                              }
                              *(undefined4 *)(plVar3 + 5) = 0x1d9;
                              local_150 = (longlong *)FUN_23e9557e0(param_1,plVar15,_DAT_23eeae028);
                              lVar12 = *plVar15;
                              *plVar15 = lVar12 + -1;
                              if (lVar12 + -1 == 0) {
                                FUN_23a334bc0(plVar15);
                              }
                              if (local_150 == (longlong *)0x0) {
                                pcVar18 = *(code **)(param_1 + 0x60);
                                pcVar21 = *(code **)(param_1 + 0x70);
                                local_158 = (longlong *)0x0;
                                uVar23 = 0x1d9;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                local_160 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                pcVar20 = *(code **)(param_1 + 0x68);
                                goto LAB_23e2d2b00;
                              }
                              plVar19 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeadb40);
                              if (plVar19 == (longlong *)0x0) {
                                pcVar18 = *(code **)(param_1 + 0x60);
                                pcVar21 = *(code **)(param_1 + 0x70);
                                local_158 = (longlong *)0x0;
                                uVar23 = 0x1da;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                local_160 = (longlong *)0x0;
                                pcVar20 = *(code **)(param_1 + 0x68);
                                goto LAB_23e2d2b00;
                              }
                              plVar15 = (longlong *)FUN_23e8bc2f0(plVar19,_DAT_23eeada60);
                              lVar12 = *plVar19;
                              *plVar19 = lVar12 + -1;
                              if (lVar12 + -1 == 0) {
                                FUN_23a334bc0(plVar19);
                              }
                              plVar19 = _DAT_23eeae030;
                              if (plVar15 == (longlong *)0x0) {
                                pcVar18 = *(code **)(param_1 + 0x60);
                                pcVar21 = *(code **)(param_1 + 0x70);
                                local_158 = (longlong *)0x0;
                                uVar23 = 0x1da;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                local_160 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                pcVar20 = *(code **)(param_1 + 0x68);
                                goto LAB_23e2d2b00;
                              }
                              plVar16 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2)
                              ;
                              *plVar19 = *plVar19 + 1;
                              plVar16[3] = (longlong)plVar19;
                              lVar12 = FUN_23e94f9d0(param_1,local_150);
                              if (lVar12 == 0) {
                                pcVar18 = *(code **)(param_1 + 0x60);
                                pcVar20 = *(code **)(param_1 + 0x68);
                                pcVar21 = *(code **)(param_1 + 0x70);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *plVar15 = *plVar15 + -1;
                                if (*plVar15 == 0) {
                                  FUN_23a334bc0(plVar15);
                                }
                                *plVar16 = *plVar16 + -1;
                                local_160 = (longlong *)0x0;
                                if (*plVar16 == 0) {
                                  FUN_23a334bc0(plVar16);
                                  uVar23 = 0x1da;
                                  local_158 = (longlong *)0x0;
                                }
                                else {
LAB_23e2d607f:
                                  local_160 = (longlong *)0x0;
                                  uVar23 = 0x1da;
                                  local_158 = (longlong *)0x0;
                                }
                                goto LAB_23e2d2b00;
                              }
                              plVar16[4] = lVar12;
                              plVar19 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar16);
                              *plVar16 = *plVar16 + -1;
                              if (*plVar16 == 0) {
                                FUN_23a334bc0(plVar16);
                              }
                              if (plVar19 == (longlong *)0x0) {
                                pcVar18 = *(code **)(param_1 + 0x60);
                                pcVar20 = *(code **)(param_1 + 0x68);
                                pcVar21 = *(code **)(param_1 + 0x70);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *plVar15 = *plVar15 + -1;
                                local_160 = (longlong *)0x0;
                                if (*plVar15 != 0) goto LAB_23e2d607f;
                                FUN_23a334bc0();
                                uVar23 = 0x1da;
                                local_158 = (longlong *)0x0;
                                goto LAB_23e2d2b00;
                              }
                              *(undefined4 *)(plVar3 + 5) = 0x1da;
                              plVar16 = (longlong *)FUN_23e914090(param_1,plVar15,plVar19);
                              *plVar15 = *plVar15 + -1;
                              if (*plVar15 == 0) {
                                FUN_23a334bc0(plVar15);
                              }
                              lVar12 = *plVar19;
                              *plVar19 = lVar12 + -1;
                              if (lVar12 + -1 == 0) {
                                FUN_23a334bc0(plVar19);
                              }
                              if (plVar16 == (longlong *)0x0) {
                                pcVar18 = *(code **)(param_1 + 0x60);
                                pcVar21 = *(code **)(param_1 + 0x70);
                                local_160 = (longlong *)0x0;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                uVar23 = 0x1da;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                local_158 = (longlong *)0x0;
                                pcVar20 = *(code **)(param_1 + 0x68);
                                goto LAB_23e2d2b00;
                              }
                              lVar12 = *plVar16;
                              *plVar16 = lVar12 + -1;
                              if (lVar12 + -1 == 0) {
                                FUN_23a334bc0(plVar16);
                              }
                              plVar19 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeadb40);
                              if (plVar19 == (longlong *)0x0) {
                                pcVar18 = *(code **)(param_1 + 0x60);
                                pcVar21 = *(code **)(param_1 + 0x70);
                                local_158 = (longlong *)0x0;
                                uVar23 = 0x1db;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                local_160 = (longlong *)0x0;
                                pcVar20 = *(code **)(param_1 + 0x68);
                                goto LAB_23e2d2b00;
                              }
                              plVar15 = (longlong *)FUN_23e8bc2f0(plVar19,_DAT_23eead9b8);
                              lVar12 = *plVar19;
                              *plVar19 = lVar12 + -1;
                              if (lVar12 + -1 == 0) {
                                FUN_23a334bc0(plVar19);
                              }
                              plVar19 = _DAT_23eeadb48;
                              if (plVar15 == (longlong *)0x0) {
                                pcVar18 = *(code **)(param_1 + 0x60);
                                pcVar21 = *(code **)(param_1 + 0x70);
                                local_158 = (longlong *)0x0;
                                uVar23 = 0x1db;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                local_160 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                pcVar20 = *(code **)(param_1 + 0x68);
                                goto LAB_23e2d2b00;
                              }
                              plVar16 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3)
                              ;
                              *plVar19 = *plVar19 + 1;
                              plVar16[3] = (longlong)plVar19;
                              lVar12 = FUN_23e8f6530();
                              if (lVar12 == 0) {
                                FUN_23e915740(param_1,&local_d8,DAT_23eeadd28);
                                pcVar21 = local_c8;
                                pcVar18 = local_d8;
                                pcVar20 = pcStack_d0;
LAB_23e2d5e9b:
                                *plVar15 = *plVar15 + -1;
                                if (*plVar15 == 0) {
                                  FUN_23a334bc0(plVar15);
                                }
                                *plVar16 = *plVar16 + -1;
                                if (*plVar16 == 0) {
                                  FUN_23a334bc0(plVar16);
                                  uVar23 = 0x1db;
                                  local_158 = (longlong *)0x0;
                                  local_160 = (longlong *)0x0;
                                }
                                else {
                                  uVar23 = 0x1db;
                                  local_158 = (longlong *)0x0;
                                  local_160 = (longlong *)0x0;
                                }
                                goto LAB_23e2d2b00;
                              }
                              lVar12 = FUN_23e94f9d0(param_1,lVar12,DAT_23ed6cd28);
                              if (lVar12 == 0) {
                                pcVar21 = *(code **)(param_1 + 0x70);
                                pcVar18 = *(code **)(param_1 + 0x60);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                pcVar20 = *(code **)(param_1 + 0x68);
                                goto LAB_23e2d5e9b;
                              }
                              plVar16[4] = lVar12;
                              plVar19 = _DAT_23eeadb58;
                              *_DAT_23eeadb58 = *_DAT_23eeadb58 + 1;
                              plVar16[5] = (longlong)plVar19;
                              plVar19 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar16);
                              *plVar16 = *plVar16 + -1;
                              if (*plVar16 == 0) {
                                FUN_23a334bc0(plVar16);
                              }
                              if (plVar19 == (longlong *)0x0) {
                                pcVar18 = *(code **)(param_1 + 0x60);
                                pcVar20 = *(code **)(param_1 + 0x68);
                                pcVar21 = *(code **)(param_1 + 0x70);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *plVar15 = *plVar15 + -1;
                                local_160 = (longlong *)0x0;
                                if (*plVar15 == 0) {
                                  FUN_23a334bc0(plVar15);
                                  uVar23 = 0x1db;
                                  local_158 = (longlong *)0x0;
                                }
                                else {
                                  uVar23 = 0x1db;
                                  local_158 = (longlong *)0x0;
                                }
                                goto LAB_23e2d2b00;
                              }
                              *(undefined4 *)(plVar3 + 5) = 0x1db;
                              plVar16 = (longlong *)FUN_23e914090(param_1,plVar15);
                              *plVar15 = *plVar15 + -1;
                              if (*plVar15 == 0) {
                                FUN_23a334bc0(plVar15);
                              }
                              lVar12 = *plVar19;
                              *plVar19 = lVar12 + -1;
                              if (lVar12 + -1 == 0) {
                                FUN_23a334bc0(plVar19);
                              }
                              if (plVar16 == (longlong *)0x0) {
                                pcVar18 = *(code **)(param_1 + 0x60);
                                pcVar21 = *(code **)(param_1 + 0x70);
                                local_160 = (longlong *)0x0;
                                uVar23 = 0x1db;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                local_158 = (longlong *)0x0;
                                pcVar20 = *(code **)(param_1 + 0x68);
                                goto LAB_23e2d2b00;
                              }
                              lVar12 = *plVar16;
                              *plVar16 = lVar12 + -1;
                              if (lVar12 + -1 == 0) {
                                FUN_23a334bc0(plVar16);
                                local_158 = (longlong *)0x0;
                                local_160 = (longlong *)0x0;
                              }
                              else {
                                local_158 = (longlong *)0x0;
                                local_160 = (longlong *)0x0;
                              }
LAB_23e2d1a58:
                              plVar19 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeadaf8);
                              lVar12 = _DAT_23eead990;
                              if (plVar19 != (longlong *)0x0) {
                                *(undefined4 *)(plVar3 + 5) = 0x1e2;
                                plVar15 = (longlong *)
                                          FUN_23e915840(param_1,plVar19,_DAT_23eeadfa8,
                                                        *(undefined8 *)(lVar12 + 0x18));
                                *plVar19 = *plVar19 + -1;
                                if (*plVar19 == 0) {
                                  FUN_23a334bc0(plVar19);
                                }
                                if (plVar15 != (longlong *)0x0) {
                                  *plVar15 = *plVar15 + -1;
                                  if (*plVar15 == 0) {
                                    FUN_23a334bc0(plVar15);
                                  }
                                  FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                                  *(longlong *)local_140 = *(longlong *)local_140 + 1;
                                  *plVar11 = *plVar11 + -1;
                                  if (*plVar11 == 0) {
                                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                                  }
                                  if ((plVar10 != (longlong *)0x0) &&
                                     (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
                                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                                  }
                                  if ((plVar9 != (longlong *)0x0) &&
                                     (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
                                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                                  }
                                  if ((plVar13 != (longlong *)0x0) &&
                                     (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
                                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                                  }
                                  if ((local_160 != (longlong *)0x0) &&
                                     (lVar12 = *local_160, *local_160 = lVar12 + -1,
                                     lVar12 + -1 == 0)) {
                                    (**(code **)(local_160[1] + 0x30))(local_160);
                                  }
                                  if ((local_158 != (longlong *)0x0) &&
                                     (lVar12 = *local_158, *local_158 = lVar12 + -1,
                                     lVar12 + -1 == 0)) {
                                    (**(code **)(local_158[1] + 0x30))(local_158);
                                  }
                                  if ((local_150 != (longlong *)0x0) &&
                                     (lVar12 = *local_150, *local_150 = lVar12 + -1,
                                     lVar12 + -1 == 0)) {
                                    (**(code **)(local_150[1] + 0x30))(local_150);
                                  }
                                  goto LAB_23e2d0744;
                                }
                              }
                              local_140 = *(code **)(param_1 + 0x60);
                              pcVar21 = *(code **)(param_1 + 0x70);
                              local_148 = *(code **)(param_1 + 0x68);
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              if (pcVar21 == (code *)0x0) {
                                iVar8 = 0x1e2;
                                goto LAB_23e2d1fb0;
                              }
                              pcVar18 = pcVar21;
                              if (plVar3 == *(longlong **)(pcVar21 + 0x18)) goto LAB_23e2d09e0;
                              iVar24 = 0x1e2;
                              goto LAB_23e2d0940;
                            }
                            pcVar18 = *(code **)(param_1 + 0x60);
                            pcVar20 = *(code **)(param_1 + 0x68);
                            pcVar21 = *(code **)(param_1 + 0x70);
                            plVar13 = (longlong *)0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            plVar9 = (longlong *)0x0;
                            uVar23 = 0x1c1;
                            local_150 = (longlong *)0x0;
                            local_158 = (longlong *)0x0;
                            local_160 = (longlong *)0x0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e2d2b00:
                            local_130 = *(longlong **)(param_1 + 0x138);
                            local_f8._8_8_ = pcVar20;
                            local_f8._0_8_ = pcVar18;
                            if (local_130 != (longlong *)0x0) {
                              *local_130 = *local_130 + 1;
                            }
                            pcVar18 = DAT_23ed6a4f8;
                            local_e8 = pcVar21;
                            if (pcVar21 == (code *)0x0) {
                              if (DAT_23ed6a4f8 == (code *)0x0) {
                                pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                              }
                              else {
                                pcVar21 = *(code **)DAT_23ed6a4f8;
                                *(undefined8 *)DAT_23ed6a4f8 = 1;
                                DAT_23ed6a4f8 = pcVar21;
                                DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                              }
                              *(longlong *)(pcVar18 + 0x10) = 0;
                              *(longlong **)(pcVar18 + 0x18) = plVar3;
                              *plVar3 = *plVar3 + 1;
                              lVar12 = *(longlong *)(local_138 + 0x1f8);
                              *(undefined4 *)(pcVar18 + 0x24) = uVar23;
                              lVar12 = *(longlong *)(lVar12 + 0x10);
                              *(undefined4 *)(pcVar18 + 0x20) = 0xffffffff;
                              lVar12 = *(longlong *)(lVar12 + 0x2e8);
                              lVar14 = *(longlong *)(pcVar18 + -8);
                              plVar19 = *(longlong **)(lVar12 + 8);
                              *plVar19 = (longlong)(pcVar18 + -0x10);
                              *(longlong *)(pcVar18 + -0x10) = lVar12;
                              *(ulonglong *)(pcVar18 + -8) =
                                   (ulonglong)((uint)lVar14 & 3) | (ulonglong)plVar19;
                              *(code **)(lVar12 + 8) = pcVar18 + -0x10;
                              if ((local_e8 != (code *)0x0) &&
                                 (*(longlong *)local_e8 = *(longlong *)local_e8 + -1,
                                 *(longlong *)local_e8 == 0)) {
                                (**(code **)(*(longlong *)(local_e8 + 8) + 0x30))(local_e8);
                              }
                            }
                            else {
                              if (DAT_23ed6a4f8 == (code *)0x0) {
                                pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                              }
                              else {
                                pcVar20 = *(code **)DAT_23ed6a4f8;
                                *(undefined8 *)DAT_23ed6a4f8 = 1;
                                DAT_23ed6a4f8 = pcVar20;
                                DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                              }
                              *(longlong **)(pcVar18 + 0x18) = plVar3;
                              *plVar3 = *plVar3 + 1;
                              lVar12 = *(longlong *)(local_138 + 0x1f8);
                              *(undefined4 *)(pcVar18 + 0x24) = uVar23;
                              *(undefined4 *)(pcVar18 + 0x20) = 0xffffffff;
                              lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
                              lVar14 = *(longlong *)(pcVar18 + -8);
                              plVar19 = *(longlong **)(lVar12 + 8);
                              *plVar19 = (longlong)(pcVar18 + -0x10);
                              *(longlong *)(pcVar18 + -0x10) = lVar12;
                              *(ulonglong *)(pcVar18 + -8) =
                                   (ulonglong)((uint)lVar14 & 3) | (ulonglong)plVar19;
                              *(code **)(lVar12 + 8) = pcVar18 + -0x10;
                              *(code **)(pcVar18 + 0x10) = pcVar21;
                              *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
                              if ((local_e8 != (code *)0x0) &&
                                 (*(longlong *)local_e8 = *(longlong *)local_e8 + -1,
                                 *(longlong *)local_e8 == 0)) {
                                (**(code **)(*(longlong *)(local_e8 + 8) + 0x30))(local_e8);
                              }
                            }
                            local_e8 = pcVar18;
                            if (((code *)local_f8._0_8_ != (code *)0x0) &&
                               ((code *)local_f8._0_8_ != local_140)) {
                              FUN_23e91b1b0(param_1,local_f8,local_f8 + 8);
                            }
                            plVar19 = *(longlong **)(local_f8._8_8_ + 0x28);
                            if (local_e8 == local_140) {
                              pcVar21 = (code *)0x0;
                            }
                            else {
                              pcVar21 = local_e8;
                              if (local_e8 != (code *)0x0) {
                                *(longlong *)local_e8 = *(longlong *)local_e8 + 1;
                              }
                            }
                            *(code **)(local_f8._8_8_ + 0x28) = pcVar21;
                            if ((plVar19 != (longlong *)0x0) &&
                               (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
                              (**(code **)(plVar19[1] + 0x30))();
                            }
                            plVar19 = *(longlong **)(param_1 + 0x138);
                            *(undefined8 *)(param_1 + 0x138) = local_f8._8_8_;
                            if ((plVar19 != (longlong *)0x0) &&
                               (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
                              (**(code **)(plVar19[1] + 0x30))();
                            }
                            *(longlong *)local_f8._0_8_ = *(longlong *)local_f8._0_8_ + -1;
                            if (*(longlong *)local_f8._0_8_ == 0) {
                              (**(code **)(*(longlong *)(local_f8._0_8_ + 8) + 0x30))();
                            }
                            if ((local_e8 != (code *)0x0) &&
                               (*(longlong *)local_e8 = *(longlong *)local_e8 + -1,
                               *(longlong *)local_e8 == 0)) {
                              (**(code **)(*(longlong *)(local_e8 + 8) + 0x30))();
                            }
                            local_e8 = (code *)0x0;
                            local_f8 = (undefined1  [16])0x0;
                            iVar8 = FUN_23a35ebd0(param_1,*(undefined8 *)
                                                           (*(longlong *)(param_1 + 0x138) + 8),
                                                  *(undefined8 *)PyExc_Exception_exref);
                            if (iVar8 == 0) {
                              pcVar21 = *(code **)(param_1 + 0x138);
                              if ((pcVar21 == local_140) || (pcVar21 == (code *)0x0)) {
                                pcVar18 = *(code **)PyExc_RuntimeError_exref;
                                pcVar20 = (code *)PyUnicode_FromString
                                                            ("No active exception to reraise");
                                pcVar25 = (code *)0x0;
                                local_148._0_4_ = 0x1c0;
                                pcVar21 = *(code **)(param_1 + 0x138);
                                *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
                                goto LAB_23e2d410e;
                              }
                              pcVar18 = *(code **)(pcVar21 + 8);
                              pcVar25 = *(code **)(pcVar21 + 0x28);
                              *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
                              *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
                              local_148._0_4_ = 0;
                              pcVar20 = pcVar21;
                              if (pcVar25 == (code *)0x0) {
                                *(longlong **)(param_1 + 0x138) = local_130;
                              }
                              else {
                                *(longlong *)pcVar25 = *(longlong *)pcVar25 + 1;
                                if (plVar3 == *(longlong **)(pcVar25 + 0x18)) {
                                  *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar25 + 0x24);
                                }
                                *(longlong **)(param_1 + 0x138) = local_130;
                              }
LAB_23e2d3a40:
                              *(longlong *)pcVar21 = *(longlong *)pcVar21 + -1;
                              if (*(longlong *)pcVar21 == 0) {
                                (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))();
                                local_130 = *(longlong **)(param_1 + 0x138);
                              }
                              local_88._8_8_ = pcVar20;
                              local_88._0_8_ = pcVar18;
                              local_78 = pcVar25;
                              if (local_130 != (longlong *)0x0) {
LAB_23e2d3acd:
                                *local_130 = *local_130 + 1;
                                local_78 = pcVar25;
                              }
                              if (local_78 == (code *)0x0) {
                                if ((int)local_148 == 0) {
                                  local_148._0_4_ = (int)plVar3[5];
                                }
                                goto LAB_23e2d4500;
                              }
                              if ((int)local_148 != 0) {
LAB_23e2d4150:
                                pcVar18 = local_78;
                                pcVar21 = DAT_23ed6a4f8;
                                if (DAT_23ed6a4f8 == (code *)0x0) {
                                  pcVar21 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                                }
                                else {
                                  pcVar20 = *(code **)DAT_23ed6a4f8;
                                  *(undefined8 *)DAT_23ed6a4f8 = 1;
                                  DAT_23ed6a4f8 = pcVar20;
                                  DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                                }
                                *(longlong **)(pcVar21 + 0x18) = plVar3;
                                *plVar3 = *plVar3 + 1;
                                lVar12 = *(longlong *)(local_138 + 0x1f8);
                                *(int *)(pcVar21 + 0x24) = (int)local_148;
                                *(undefined4 *)(pcVar21 + 0x20) = 0xffffffff;
                                lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
                                lVar14 = *(longlong *)(pcVar21 + -8);
                                plVar19 = *(longlong **)(lVar12 + 8);
                                *plVar19 = (longlong)(pcVar21 + -0x10);
                                *(longlong *)(pcVar21 + -0x10) = lVar12;
                                *(ulonglong *)(pcVar21 + -8) =
                                     (ulonglong)((uint)lVar14 & 3) | (ulonglong)plVar19;
                                *(code **)(lVar12 + 8) = pcVar21 + -0x10;
                                *(code **)(pcVar21 + 0x10) = pcVar18;
                                *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
                                if ((local_78 != (code *)0x0) &&
                                   (*(longlong *)local_78 = *(longlong *)local_78 + -1,
                                   *(longlong *)local_78 == 0)) {
                                  (**(code **)(*(longlong *)(local_78 + 8) + 0x30))(local_78);
                                }
                                pcVar18 = (code *)local_88._0_8_;
                                local_78 = pcVar21;
                              }
                            }
                            else {
                              plVar19 = *(longlong **)(param_1 + 0x138);
                              *plVar19 = *plVar19 + 1;
                              lVar12 = FUN_23e8f6a70();
                              if (lVar12 == 0) {
                                FUN_23e915740(param_1,&local_d8,DAT_23eeadcf8);
                                local_148._0_4_ = 0x1de;
                                pcVar20 = pcStack_d0;
                                pcVar25 = local_c8;
                                pcVar18 = local_d8;
                              }
                              else {
                                plVar15 = (longlong *)FUN_23e8bc2f0(lVar12,_DAT_23eeade28);
                                plVar16 = _DAT_23eeae038;
                                if (plVar15 == (longlong *)0x0) {
                                  pcVar18 = *(code **)(param_1 + 0x60);
                                  local_148._0_4_ = 0x1de;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  pcVar25 = *(code **)(param_1 + 0x70);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  pcVar20 = *(code **)(param_1 + 0x68);
                                }
                                else {
                                  lVar12 = *(longlong *)(param_1 + 0x10);
                                  plVar17 = *(longlong **)(lVar12 + 0xe20);
                                  if (plVar17 == (longlong *)0x0) {
                                    plVar17 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                                  }
                                  else {
                                    lVar14 = plVar17[3];
                                    *(int *)(lVar12 + 0xebc) = *(int *)(lVar12 + 0xebc) + -1;
                                    *(longlong *)(lVar12 + 0xe20) = lVar14;
                                    *plVar17 = 1;
                                  }
                                  plVar17[4] = 0;
                                  lVar12 = *(longlong *)
                                            (*(longlong *)(*(longlong *)(local_138 + 0x1f8) + 0x10)
                                            + 0x2e8);
                                  lVar14 = plVar17[-1];
                                  puVar2 = *(undefined8 **)(lVar12 + 8);
                                  *puVar2 = plVar17 + -2;
                                  plVar17[-2] = lVar12;
                                  plVar17[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar2;
                                  *(longlong **)(lVar12 + 8) = plVar17 + -2;
                                  *plVar16 = *plVar16 + 1;
                                  plVar17[3] = (longlong)plVar16;
                                  uVar5 = DAT_23ed6cd28;
                                  if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                    plVar16 = (longlong *)
                                              PyDict_GetItemString(DAT_23ed6ccc0,"format");
                                    if (plVar16 == (longlong *)0x0) goto LAB_23e2d4214;
                                    *plVar16 = *plVar16 + 1;
                                    DAT_23ed6a4c0 = plVar16;
                                  }
                                  local_88._8_8_ = uVar5;
                                  local_88._0_8_ = plVar19;
                                  lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,local_88);
                                  if (lVar12 == 0) {
                                    pcVar18 = *(code **)(param_1 + 0x60);
                                    pcVar20 = *(code **)(param_1 + 0x68);
                                    pcVar25 = *(code **)(param_1 + 0x70);
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    lVar12 = *plVar15;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    *plVar15 = lVar12 + -1;
                                    if (lVar12 + -1 == 0) {
                                      (**(code **)(plVar15[1] + 0x30))(plVar15);
                                    }
                                    *plVar17 = *plVar17 + -1;
                                    local_148._0_4_ = 0x1de;
                                    if (*plVar17 == 0) {
                                      local_148._0_4_ = 0x1de;
                                      (**(code **)(plVar17[1] + 0x30))(plVar17);
                                    }
                                  }
                                  else {
                                    plVar17[4] = lVar12;
                                    plVar16 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar17);
                                    *plVar17 = *plVar17 + -1;
                                    if (*plVar17 == 0) {
                                      (**(code **)(plVar17[1] + 0x30))(plVar17);
                                    }
                                    if (plVar16 == (longlong *)0x0) {
                                      pcVar18 = *(code **)(param_1 + 0x60);
                                      pcVar20 = *(code **)(param_1 + 0x68);
                                      pcVar25 = *(code **)(param_1 + 0x70);
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      local_148._0_4_ = 0x1de;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      lVar12 = *plVar15 + -1;
                                      *plVar15 = lVar12;
joined_r0x00023e2d5284:
                                      if (lVar12 == 0) {
                                        FUN_23a334bc0(plVar15);
                                      }
                                    }
                                    else {
                                      *(undefined4 *)(plVar3 + 5) = 0x1de;
                                      plVar17 = (longlong *)FUN_23e914090(param_1,plVar15);
                                      lVar12 = *plVar15;
                                      *plVar15 = lVar12 + -1;
                                      if (lVar12 + -1 == 0) {
                                        (**(code **)(plVar15[1] + 0x30))();
                                      }
                                      *plVar16 = *plVar16 + -1;
                                      if (*plVar16 == 0) {
                                        (**(code **)(plVar16[1] + 0x30))();
                                      }
                                      if (plVar17 == (longlong *)0x0) {
                                        pcVar18 = *(code **)(param_1 + 0x60);
                                        pcVar25 = *(code **)(param_1 + 0x70);
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        local_148._0_4_ = 0x1de;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        pcVar20 = *(code **)(param_1 + 0x68);
                                      }
                                      else {
                                        *plVar17 = *plVar17 + -1;
                                        if (*plVar17 == 0) {
                                          (**(code **)(plVar17[1] + 0x30))(plVar17);
                                        }
                                        plVar16 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeadb40);
                                        if (plVar16 != (longlong *)0x0) {
                                          plVar15 = (longlong *)
                                                    FUN_23e8bc2f0(plVar16,_DAT_23eeada60);
                                          *plVar16 = *plVar16 + -1;
                                          if (*plVar16 == 0) {
                                            (**(code **)(plVar16[1] + 0x30))(plVar16);
                                          }
                                          plVar16 = _DAT_23eeae040;
                                          if (plVar15 != (longlong *)0x0) {
                                            lVar12 = *(longlong *)(param_1 + 0x10);
                                            plVar17 = *(longlong **)(lVar12 + 0xe20);
                                            if (plVar17 == (longlong *)0x0) {
                                              plVar17 = (longlong *)
                                                        FUN_23e916a20(PyTuple_Type_exref,2);
                                            }
                                            else {
                                              lVar14 = plVar17[3];
                                              *(int *)(lVar12 + 0xebc) =
                                                   *(int *)(lVar12 + 0xebc) + -1;
                                              *(longlong *)(lVar12 + 0xe20) = lVar14;
                                              *plVar17 = 1;
                                            }
                                            plVar17[4] = 0;
                                            lVar12 = *(longlong *)
                                                      (*(longlong *)
                                                        (*(longlong *)(local_138 + 0x1f8) + 0x10) +
                                                      0x2e8);
                                            lVar14 = plVar17[-1];
                                            puVar2 = *(undefined8 **)(lVar12 + 8);
                                            *puVar2 = plVar17 + -2;
                                            plVar17[-2] = lVar12;
                                            plVar17[-1] = (ulonglong)((uint)lVar14 & 3) |
                                                          (ulonglong)puVar2;
                                            *(longlong **)(lVar12 + 8) = plVar17 + -2;
                                            *plVar16 = *plVar16 + 1;
                                            plVar17[3] = (longlong)plVar16;
                                            plVar16 = (longlong *)FUN_23e8bd350(plVar19);
                                            uVar5 = DAT_23ed6cd28;
                                            if (plVar16 != (longlong *)0x0) {
                                              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                                plVar22 = (longlong *)
                                                          PyDict_GetItemString
                                                                    (DAT_23ed6ccc0,"format");
                                                if (plVar22 == (longlong *)0x0) goto LAB_23e2d4214;
                                                *plVar22 = *plVar22 + 1;
                                                DAT_23ed6a4c0 = plVar22;
                                              }
                                              local_88._8_8_ = uVar5;
                                              local_88._0_8_ = plVar16;
                                              lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,local_88)
                                              ;
                                              *plVar16 = *plVar16 + -1;
                                              if (*plVar16 == 0) {
                                                (**(code **)(plVar16[1] + 0x30))(plVar16);
                                              }
                                              if (lVar12 != 0) {
                                                plVar17[4] = lVar12;
                                                plVar16 = (longlong *)PyUnicode_Join(DAT_23ed6cd28);
                                                *plVar17 = *plVar17 + -1;
                                                if (*plVar17 == 0) {
                                                  (**(code **)(plVar17[1] + 0x30))(plVar17);
                                                }
                                                if (plVar16 == (longlong *)0x0) {
                                                  pcVar18 = *(code **)(param_1 + 0x60);
                                                  pcVar20 = *(code **)(param_1 + 0x68);
                                                  pcVar25 = *(code **)(param_1 + 0x70);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  local_148._0_4_ = 0x1df;
                                                  lVar12 = *plVar15 + -1;
                                                  *plVar15 = lVar12;
                                                  goto joined_r0x00023e2d5284;
                                                }
                                                *(undefined4 *)(plVar3 + 5) = 0x1df;
                                                plVar17 = (longlong *)FUN_23e914090(param_1,plVar15)
                                                ;
                                                lVar12 = *plVar15;
                                                *plVar15 = lVar12 + -1;
                                                if (lVar12 + -1 == 0) {
                                                  FUN_23a334bc0();
                                                }
                                                *plVar16 = *plVar16 + -1;
                                                if (*plVar16 == 0) {
                                                  FUN_23a334bc0(plVar16);
                                                }
                                                if (plVar17 == (longlong *)0x0) goto LAB_23e2d4a2f;
                                                *plVar17 = *plVar17 + -1;
                                                if (*plVar17 == 0) {
                                                  FUN_23a334bc0(plVar17);
                                                }
                                                plVar15 = (longlong *)
                                                          FUN_23e8bc2f0(plVar1,_DAT_23eeadb40);
                                                if (plVar15 != (longlong *)0x0) {
                                                  plVar16 = (longlong *)
                                                            FUN_23e8bc2f0(plVar15,_DAT_23eead9b8);
                                                  *plVar15 = *plVar15 + -1;
                                                  if (*plVar15 == 0) {
                                                    FUN_23a334bc0(plVar15);
                                                  }
                                                  plVar17 = _DAT_23eeadb48;
                                                  if (plVar16 != (longlong *)0x0) {
                                                    lVar12 = *(longlong *)(param_1 + 0x10);
                                                    plVar15 = *(longlong **)(lVar12 + 0xe28);
                                                    if (plVar15 == (longlong *)0x0) {
                                                      plVar15 = (longlong *)
                                                                FUN_23e916a20(PyTuple_Type_exref,3);
                                                    }
                                                    else {
                                                      lVar14 = plVar15[3];
                                                      *(int *)(lVar12 + 0xec0) =
                                                           *(int *)(lVar12 + 0xec0) + -1;
                                                      *(longlong *)(lVar12 + 0xe28) = lVar14;
                                                      *plVar15 = 1;
                                                    }
                                                    *(undefined1 (*) [16])(plVar15 + 4) =
                                                         (undefined1  [16])0x0;
                                                    lVar12 = *(longlong *)
                                                              (*(longlong *)
                                                                (*(longlong *)(local_138 + 0x1f8) +
                                                                0x10) + 0x2e8);
                                                    lVar14 = plVar15[-1];
                                                    puVar2 = *(undefined8 **)(lVar12 + 8);
                                                    *puVar2 = plVar15 + -2;
                                                    plVar15[-2] = lVar12;
                                                    plVar15[-1] = (ulonglong)((uint)lVar14 & 3) |
                                                                  (ulonglong)puVar2;
                                                    *(longlong **)(lVar12 + 8) = plVar15 + -2;
                                                    *plVar17 = *plVar17 + 1;
                                                    plVar15[3] = (longlong)plVar17;
                                                    lVar12 = FUN_23e8f6530();
                                                    uVar5 = DAT_23ed6cd28;
                                                    if (lVar12 == 0) {
                                                      FUN_23e915740(param_1,&local_d8,DAT_23eeadd28)
                                                      ;
                                                      pcVar20 = pcStack_d0;
                                                      pcVar25 = local_c8;
                                                      pcVar18 = local_d8;
                                                    }
                                                    else {
                                                      if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                                        plVar17 = (longlong *)
                                                                  PyDict_GetItemString
                                                                            (DAT_23ed6ccc0,"format")
                                                        ;
                                                        if (plVar17 == (longlong *)0x0)
                                                        goto LAB_23e2d4214;
                                                        *plVar17 = *plVar17 + 1;
                                                        DAT_23ed6a4c0 = plVar17;
                                                      }
                                                      local_88._8_8_ = uVar5;
                                                      local_88._0_8_ = lVar12;
                                                      lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,
                                                                             local_88);
                                                      if (lVar12 != 0) {
                                                        plVar15[4] = lVar12;
                                                        plVar17 = _DAT_23eeadb58;
                                                        *_DAT_23eeadb58 = *_DAT_23eeadb58 + 1;
                                                        plVar15[5] = (longlong)plVar17;
                                                        plVar17 = (longlong *)
                                                                  PyUnicode_Join(DAT_23ed6cd28,
                                                                                 plVar15);
                                                        *plVar15 = *plVar15 + -1;
                                                        if (*plVar15 == 0) {
                                                          FUN_23a334bc0(plVar15);
                                                        }
                                                        if (plVar17 == (longlong *)0x0) {
                                                          pcVar25 = *(code **)(param_1 + 0x70);
                                                          pcVar18 = *(code **)(param_1 + 0x60);
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          local_148._0_4_ = 0x1e0;
                                                          pcVar20 = *(code **)(param_1 + 0x68);
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          lVar12 = *plVar16 + -1;
                                                          *plVar16 = lVar12;
                                                          plVar15 = plVar16;
                                                          goto joined_r0x00023e2d5284;
                                                        }
                                                        *(undefined4 *)(plVar3 + 5) = 0x1e0;
                                                        plVar15 = (longlong *)
                                                                  FUN_23e914090(param_1,plVar16);
                                                        lVar12 = *plVar16;
                                                        *plVar16 = lVar12 + -1;
                                                        if (lVar12 + -1 == 0) {
                                                          FUN_23a334bc0();
                                                        }
                                                        *plVar17 = *plVar17 + -1;
                                                        if (*plVar17 == 0) {
                                                          FUN_23a334bc0(plVar17);
                                                        }
                                                        if (plVar15 != (longlong *)0x0) {
                                                          *plVar15 = *plVar15 + -1;
                                                          if (*plVar15 == 0) {
                                                            FUN_23a334bc0(plVar15);
                                                          }
                                                          lVar12 = *plVar19;
                                                          *plVar19 = lVar12 + -1;
                                                          if (lVar12 + -1 == 0) {
                                                            FUN_23a334bc0(plVar19);
                                                          }
                                                          FUN_23ebf6ae0(param_1,local_130);
                                                          goto LAB_23e2d1a58;
                                                        }
                                                        goto LAB_23e2d5083;
                                                      }
                                                      pcVar25 = *(code **)(param_1 + 0x70);
                                                      pcVar18 = *(code **)(param_1 + 0x60);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      pcVar20 = *(code **)(param_1 + 0x68);
                                                    }
                                                    lVar12 = *plVar16;
                                                    *plVar16 = lVar12 + -1;
                                                    if (lVar12 + -1 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    *plVar15 = *plVar15 + -1;
                                                    lVar12 = *plVar15;
                                                    local_148._0_4_ = 0x1e0;
                                                    goto joined_r0x00023e2d5284;
                                                  }
                                                }
LAB_23e2d5083:
                                                pcVar18 = *(code **)(param_1 + 0x60);
                                                pcVar25 = *(code **)(param_1 + 0x70);
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                                local_148._0_4_ = 0x1e0;
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                pcVar20 = *(code **)(param_1 + 0x68);
                                                goto LAB_23e2d4096;
                                              }
                                            }
                                            pcVar18 = *(code **)(param_1 + 0x60);
                                            pcVar20 = *(code **)(param_1 + 0x68);
                                            pcVar25 = *(code **)(param_1 + 0x70);
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            lVar12 = *plVar15;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            *plVar15 = lVar12 + -1;
                                            if (lVar12 + -1 == 0) {
                                              FUN_23a334bc0();
                                            }
                                            *plVar17 = *plVar17 + -1;
                                            lVar12 = *plVar17;
                                            local_148._0_4_ = 0x1df;
                                            plVar15 = plVar17;
                                            goto joined_r0x00023e2d5284;
                                          }
                                        }
LAB_23e2d4a2f:
                                        pcVar18 = *(code **)(param_1 + 0x60);
                                        local_148._0_4_ = 0x1df;
                                        pcVar25 = *(code **)(param_1 + 0x70);
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        pcVar20 = *(code **)(param_1 + 0x68);
                                      }
                                    }
                                  }
                                }
                              }
LAB_23e2d4096:
                              lVar12 = *plVar19;
                              *plVar19 = lVar12 + -1;
                              if (lVar12 + -1 == 0) {
                                (**(code **)(plVar19[1] + 0x30))();
                              }
                              pcVar21 = *(code **)(param_1 + 0x138);
LAB_23e2d410e:
                              *(longlong **)(param_1 + 0x138) = local_130;
                              if (pcVar21 != (code *)0x0) goto LAB_23e2d3a40;
                              local_88._8_8_ = pcVar20;
                              local_88._0_8_ = pcVar18;
                              if (local_130 != (longlong *)0x0) goto LAB_23e2d3acd;
                              local_78 = pcVar25;
                              if (pcVar25 != (code *)0x0) goto LAB_23e2d4150;
LAB_23e2d4500:
                              pcVar21 = DAT_23ed6a4f8;
                              if (DAT_23ed6a4f8 == (code *)0x0) {
                                pcVar21 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                                pcVar18 = local_78;
                              }
                              else {
                                pcVar18 = *(code **)DAT_23ed6a4f8;
                                *(undefined8 *)DAT_23ed6a4f8 = 1;
                                DAT_23ed6a4f8 = pcVar18;
                                DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                                pcVar18 = (code *)0x0;
                              }
                              *(longlong *)(pcVar21 + 0x10) = 0;
                              *(longlong **)(pcVar21 + 0x18) = plVar3;
                              *plVar3 = *plVar3 + 1;
                              lVar12 = *(longlong *)(local_138 + 0x1f8);
                              *(int *)(pcVar21 + 0x24) = (int)local_148;
                              lVar12 = *(longlong *)(lVar12 + 0x10);
                              *(undefined4 *)(pcVar21 + 0x20) = 0xffffffff;
                              lVar12 = *(longlong *)(lVar12 + 0x2e8);
                              lVar14 = *(longlong *)(pcVar21 + -8);
                              plVar19 = *(longlong **)(lVar12 + 8);
                              *plVar19 = (longlong)(pcVar21 + -0x10);
                              *(longlong *)(pcVar21 + -0x10) = lVar12;
                              *(ulonglong *)(pcVar21 + -8) =
                                   (ulonglong)((uint)lVar14 & 3) | (ulonglong)plVar19;
                              *(code **)(lVar12 + 8) = pcVar21 + -0x10;
                              if ((pcVar18 != (code *)0x0) &&
                                 (*(longlong *)pcVar18 = *(longlong *)pcVar18 + -1,
                                 *(longlong *)pcVar18 == 0)) {
                                FUN_23a334bc0(pcVar18);
                              }
                              pcVar18 = (code *)local_88._0_8_;
                              local_78 = pcVar21;
                            }
                            if ((pcVar18 != (code *)0x0) && (pcVar18 != local_140)) {
                              FUN_23e91b1b0(param_1,local_88,local_88 + 8,&local_78);
                            }
                            plVar19 = *(longlong **)(local_88._8_8_ + 0x28);
                            if (local_78 == local_140) {
                              pcVar21 = (code *)0x0;
                            }
                            else {
                              pcVar21 = local_78;
                              if (local_78 != (code *)0x0) {
                                *(longlong *)local_78 = *(longlong *)local_78 + 1;
                              }
                            }
                            *(code **)(local_88._8_8_ + 0x28) = pcVar21;
                            if ((plVar19 != (longlong *)0x0) &&
                               (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
                              (**(code **)(plVar19[1] + 0x30))();
                            }
                            plVar19 = *(longlong **)(param_1 + 0x138);
                            *(undefined8 *)(param_1 + 0x138) = local_88._8_8_;
                            if ((plVar19 != (longlong *)0x0) &&
                               (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
                              (**(code **)(plVar19[1] + 0x30))();
                            }
                            *(longlong *)local_88._0_8_ = *(longlong *)local_88._0_8_ + -1;
                            if (*(longlong *)local_88._0_8_ == 0) {
                              (**(code **)(*(longlong *)(local_88._0_8_ + 8) + 0x30))();
                            }
                            if ((local_78 != (code *)0x0) &&
                               (*(longlong *)local_78 = *(longlong *)local_78 + -1,
                               *(longlong *)local_78 == 0)) {
                              (**(code **)(*(longlong *)(local_78 + 8) + 0x30))();
                            }
                            local_78 = (code *)0x0;
                            local_88 = (undefined1  [16])0x0;
                            plVar19 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeadaf8);
                            lVar12 = _DAT_23eead990;
                            if (plVar19 == (longlong *)0x0) {
                              local_140 = *(code **)(param_1 + 0x60);
                              pcVar18 = *(code **)(param_1 + 0x138);
                              pcVar21 = *(code **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              local_148 = *(code **)(param_1 + 0x68);
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              *(longlong **)(param_1 + 0x138) = local_130;
                              if (pcVar18 == (code *)0x0) {
                                if (pcVar21 != (code *)0x0) goto LAB_23e2d43bd;
                              }
                              else {
LAB_23e2d3df1:
                                *(longlong *)pcVar18 = *(longlong *)pcVar18 + -1;
                                if (*(longlong *)pcVar18 == 0) {
                                  iVar24 = 0x1e2;
                                  goto LAB_23e2d446e;
                                }
                                if (pcVar21 != (code *)0x0) {
                                  plVar19 = *(longlong **)(pcVar21 + 0x18);
                                  goto joined_r0x00023e2d3e0b;
                                }
                              }
LAB_23e2d50c0:
                              iVar8 = 0x1e2;
                              goto LAB_23e2d1fb0;
                            }
                            *(undefined4 *)(plVar3 + 5) = 0x1e2;
                            plVar15 = (longlong *)
                                      FUN_23e915840(param_1,plVar19,_DAT_23eeadfa8,
                                                    *(undefined8 *)(lVar12 + 0x18));
                            *plVar19 = *plVar19 + -1;
                            if (*plVar19 == 0) {
                              (**(code **)(plVar19[1] + 0x30))(plVar19);
                            }
                            if (plVar15 == (longlong *)0x0) {
                              local_140 = *(code **)(param_1 + 0x60);
                              pcVar18 = *(code **)(param_1 + 0x138);
                              pcVar21 = *(code **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              local_148 = *(code **)(param_1 + 0x68);
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              *(longlong **)(param_1 + 0x138) = local_130;
                              if (pcVar18 != (code *)0x0) goto LAB_23e2d3df1;
                              if (pcVar21 == (code *)0x0) goto LAB_23e2d50c0;
LAB_23e2d43bd:
                              plVar19 = *(longlong **)(pcVar21 + 0x18);
joined_r0x00023e2d3e0b:
                              pcVar18 = pcVar21;
                              if (plVar19 == plVar3) goto LAB_23e2d09e0;
                              iVar24 = 0x1e2;
                              goto LAB_23e2d0940;
                            }
                            *plVar15 = *plVar15 + -1;
                            if (*plVar15 == 0) {
                              (**(code **)(plVar15[1] + 0x30))(plVar15);
                            }
                            pcVar18 = *(code **)(param_1 + 0x138);
                            if ((pcVar18 == local_140) || (pcVar18 == (code *)0x0)) {
                              local_140 = *(code **)PyExc_RuntimeError_exref;
                              local_148 = (code *)PyUnicode_FromString
                                                            ("No active exception to reraise");
                              *(longlong *)local_140 = *(longlong *)local_140 + 1;
                              pcVar18 = *(code **)(param_1 + 0x138);
                              iVar8 = 0x1c0;
                              iVar24 = 0x1c0;
                              *(longlong **)(param_1 + 0x138) = local_130;
                              if ((pcVar18 == (code *)0x0) ||
                                 (*(longlong *)pcVar18 = *(longlong *)pcVar18 + -1,
                                 *(longlong *)pcVar18 != 0)) goto LAB_23e2d1fb0;
                              pcVar21 = (code *)0x0;
LAB_23e2d446e:
                              (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))();
                              if (pcVar21 == (code *)0x0) {
                                iVar8 = iVar24;
                                if (iVar24 != 0) goto LAB_23e2d1fb0;
LAB_23e2d44b7:
                                iVar8 = (int)plVar3[5];
                                goto LAB_23e2d1fb0;
                              }
LAB_23e2d3d8e:
                              pcVar18 = pcVar21;
                              if (*(longlong **)(pcVar21 + 0x18) == plVar3) goto LAB_23e2d09e0;
                              if (iVar24 != 0) goto LAB_23e2d0940;
                            }
                            else {
                              local_140 = *(code **)(pcVar18 + 8);
                              *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
                              *(longlong *)local_140 = *(longlong *)local_140 + 1;
                              pcVar21 = *(code **)(pcVar18 + 0x28);
                              local_148 = pcVar18;
                              if (pcVar21 == (code *)0x0) {
                                *(longlong **)(param_1 + 0x138) = local_130;
                                lVar12 = *(longlong *)pcVar18;
                                *(longlong *)pcVar18 = lVar12 + -1;
                                if (lVar12 + -1 == 0) {
                                  iVar24 = 0;
                                  goto LAB_23e2d446e;
                                }
                                goto LAB_23e2d44b7;
                              }
                              *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
                              if (plVar3 == *(longlong **)(pcVar21 + 0x18)) {
                                *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar21 + 0x24);
                              }
                              *(longlong **)(param_1 + 0x138) = local_130;
                              lVar12 = *(longlong *)pcVar18;
                              *(longlong *)pcVar18 = lVar12 + -1;
                              if (lVar12 + -1 == 0) {
                                (**(code **)(local_140 + 0x30))();
                                iVar24 = 0;
                                goto LAB_23e2d3d8e;
                              }
                              pcVar18 = pcVar21;
                              if (*(longlong **)(pcVar21 + 0x18) == plVar3) goto LAB_23e2d09e0;
                            }
                            iVar24 = (int)plVar3[5];
                            goto LAB_23e2d0940;
                          }
                          local_140 = *(code **)(param_1 + 0x60);
                          pcVar21 = *(code **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          local_148 = *(code **)(param_1 + 0x68);
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          local_160 = (longlong *)0x0;
                          if (pcVar21 == (code *)0x0) {
                            plVar13 = (longlong *)0x0;
                            plVar9 = (longlong *)0x0;
                            local_150 = (longlong *)0x0;
                            local_158 = (longlong *)0x0;
                            iVar8 = 0x1be;
                            plVar10 = (longlong *)0x0;
                            goto LAB_23e2d1fb0;
                          }
                          if (plVar3 == *(longlong **)(pcVar21 + 0x18)) {
                            plVar9 = (longlong *)0x0;
                            plVar10 = (longlong *)0x0;
                            local_150 = (longlong *)0x0;
                            local_158 = (longlong *)0x0;
                            plVar13 = (longlong *)0x0;
                            pcVar18 = pcVar21;
                            goto LAB_23e2d09e0;
                          }
                        }
                        local_160 = (longlong *)0x0;
                        local_150 = (longlong *)0x0;
                        local_158 = (longlong *)0x0;
                        plVar13 = (longlong *)0x0;
                        plVar9 = (longlong *)0x0;
                        plVar10 = (longlong *)0x0;
                        iVar24 = 0x1be;
                      }
                    }
                  }
                }
              }
            }
          }
          goto LAB_23e2d0940;
        }
        local_140 = *(code **)(param_1 + 0x60);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        local_148 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (pcVar21 != (code *)0x0) {
          if (plVar3 == *(longlong **)(pcVar21 + 0x18)) goto LAB_23e2d0e70;
          goto LAB_23e2d20b9;
        }
      }
      plVar9 = (longlong *)0x0;
      local_150 = (longlong *)0x0;
      local_158 = (longlong *)0x0;
      local_160 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      iVar8 = 0x1b6;
      local_138 = _PyRuntime_exref;
      goto LAB_23e2d1fb0;
    }
    plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeadb40);
    lVar12 = _DAT_23eeadf98;
    if (plVar9 == (longlong *)0x0) {
      local_140 = *(code **)(param_1 + 0x60);
      pcVar21 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_148 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (pcVar21 == (code *)0x0) {
        plVar13 = (longlong *)0x0;
        local_150 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        local_158 = (longlong *)0x0;
        local_160 = (longlong *)0x0;
        local_138 = _PyRuntime_exref;
        plVar10 = (longlong *)0x0;
        iVar8 = 0x1b2;
        goto LAB_23e2d1fb0;
      }
      plVar10 = (longlong *)0x0;
      if (*(longlong **)(pcVar21 + 0x18) != plVar3) {
        plVar13 = (longlong *)0x0;
        local_150 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        local_158 = (longlong *)0x0;
        iVar24 = 0x1b2;
        local_160 = (longlong *)0x0;
        local_138 = _PyRuntime_exref;
        plVar10 = (longlong *)0x0;
        goto LAB_23e2d0940;
      }
LAB_23e2d1f40:
      local_150 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      local_158 = (longlong *)0x0;
      local_160 = (longlong *)0x0;
      pcVar18 = pcVar21;
      goto LAB_23e2d09e0;
    }
    *(undefined4 *)(plVar3 + 5) = 0x1b2;
    plVar10 = (longlong *)
              FUN_23e915840(param_1,plVar9,_DAT_23eeada60,*(undefined8 *)(lVar12 + 0x18));
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    if (plVar10 == (longlong *)0x0) {
      local_140 = *(code **)(param_1 + 0x60);
      pcVar21 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_148 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (pcVar21 == (code *)0x0) {
        plVar13 = (longlong *)0x0;
        local_150 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        local_158 = (longlong *)0x0;
        local_160 = (longlong *)0x0;
        local_138 = _PyRuntime_exref;
        plVar9 = (longlong *)0x0;
        iVar8 = 0x1b2;
        goto LAB_23e2d1fb0;
      }
      if (*(longlong **)(pcVar21 + 0x18) == plVar3) {
LAB_23e2d20e0:
        plVar9 = (longlong *)0x0;
        local_150 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        local_158 = (longlong *)0x0;
        local_160 = (longlong *)0x0;
        pcVar18 = pcVar21;
        goto LAB_23e2d09e0;
      }
      plVar13 = (longlong *)0x0;
      local_150 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      local_158 = (longlong *)0x0;
      iVar24 = 0x1b2;
      local_160 = (longlong *)0x0;
      local_138 = _PyRuntime_exref;
      plVar9 = (longlong *)0x0;
    }
    else {
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eeadb40);
      if (plVar10 == (longlong *)0x0) {
        local_140 = *(code **)(param_1 + 0x60);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        local_148 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (pcVar21 == (code *)0x0) {
          plVar13 = (longlong *)0x0;
          local_150 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          local_158 = (longlong *)0x0;
          local_160 = (longlong *)0x0;
          local_138 = _PyRuntime_exref;
          iVar8 = 0x1b3;
          goto LAB_23e2d1fb0;
        }
        if (*(longlong **)(pcVar21 + 0x18) == plVar3) goto LAB_23e2d1f40;
        plVar13 = (longlong *)0x0;
        local_150 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        local_158 = (longlong *)0x0;
        iVar24 = 0x1b3;
        local_160 = (longlong *)0x0;
        local_138 = _PyRuntime_exref;
      }
      else {
        plVar9 = (longlong *)FUN_23e8bc2f0(plVar10,_DAT_23eead9b8);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        plVar13 = _DAT_23eeadb48;
        if (plVar9 != (longlong *)0x0) {
          lVar12 = *(longlong *)(param_1 + 0x10);
          plVar19 = *(longlong **)(lVar12 + 0xe28);
          if (plVar19 == (longlong *)0x0) {
            plVar19 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
          }
          else {
            lVar14 = plVar19[3];
            *(int *)(lVar12 + 0xec0) = *(int *)(lVar12 + 0xec0) + -1;
            *(longlong *)(lVar12 + 0xe28) = lVar14;
            *plVar19 = 1;
          }
          local_138 = _PyRuntime_exref;
          *(undefined1 (*) [16])(plVar19 + 4) = (undefined1  [16])0x0;
          lVar12 = *(longlong *)(*(longlong *)(*(longlong *)(local_138 + 0x1f8) + 0x10) + 0x2e8);
          lVar14 = plVar19[-1];
          puVar2 = *(undefined8 **)(lVar12 + 8);
          *puVar2 = plVar19 + -2;
          plVar19[-2] = lVar12;
          plVar19[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar2;
          *(longlong **)(lVar12 + 8) = plVar19 + -2;
          *plVar13 = *plVar13 + 1;
          plVar19[3] = (longlong)plVar13;
          lVar12 = FUN_23e8f6920();
          uVar5 = DAT_23ed6cd28;
          if (lVar12 == 0) {
            FUN_23e915740(param_1,&local_d8,DAT_23eeadd50);
            local_140 = local_d8;
            local_148 = pcStack_d0;
            pcVar21 = local_c8;
          }
          else {
            if (DAT_23ed6a4c0 == (longlong *)0x0) {
              plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              if (plVar13 == (longlong *)0x0) goto LAB_23e2d4214;
              *plVar13 = *plVar13 + 1;
              DAT_23ed6a4c0 = plVar13;
            }
            local_88._8_8_ = uVar5;
            local_88._0_8_ = lVar12;
            lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,local_88);
            if (lVar12 != 0) {
              plVar19[4] = lVar12;
              plVar10 = _DAT_23eeadb58;
              *_DAT_23eeadb58 = *_DAT_23eeadb58 + 1;
              plVar19[5] = (longlong)plVar10;
              plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar19);
              *plVar19 = *plVar19 + -1;
              if (*plVar19 == 0) {
                (**(code **)(plVar19[1] + 0x30))(plVar19);
              }
              if (plVar10 == (longlong *)0x0) {
                local_140 = *(code **)(param_1 + 0x60);
                pcVar21 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                local_148 = *(code **)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                }
                if (pcVar21 != (code *)0x0) {
                  plVar10 = (longlong *)0x0;
                  if (plVar3 == *(longlong **)(pcVar21 + 0x18)) goto LAB_23e2d1f40;
                  local_150 = (longlong *)0x0;
                  plVar13 = (longlong *)0x0;
                  plVar9 = (longlong *)0x0;
                  local_158 = (longlong *)0x0;
                  iVar24 = 0x1b3;
                  local_160 = (longlong *)0x0;
                  plVar10 = (longlong *)0x0;
                  goto LAB_23e2d0940;
                }
                local_150 = (longlong *)0x0;
                plVar13 = (longlong *)0x0;
                plVar9 = (longlong *)0x0;
                local_158 = (longlong *)0x0;
                local_160 = (longlong *)0x0;
                plVar10 = (longlong *)0x0;
                iVar8 = 0x1b3;
                goto LAB_23e2d1fb0;
              }
              *(undefined4 *)(plVar3 + 5) = 0x1b3;
              plVar13 = (longlong *)FUN_23e914090(param_1,plVar9,plVar10);
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              if (plVar13 == (longlong *)0x0) {
                local_140 = *(code **)(param_1 + 0x60);
                pcVar21 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                local_148 = *(code **)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (pcVar21 == (code *)0x0) {
                  local_150 = (longlong *)0x0;
                  plVar9 = (longlong *)0x0;
                  plVar10 = (longlong *)0x0;
                  local_158 = (longlong *)0x0;
                  local_160 = (longlong *)0x0;
                  plVar13 = (longlong *)0x0;
                  iVar8 = 0x1b3;
                  goto LAB_23e2d1fb0;
                }
                if (*(longlong **)(pcVar21 + 0x18) != plVar3) {
                  local_150 = (longlong *)0x0;
                  plVar9 = (longlong *)0x0;
                  plVar10 = (longlong *)0x0;
                  local_158 = (longlong *)0x0;
                  iVar24 = 0x1b3;
                  local_160 = (longlong *)0x0;
                  plVar13 = (longlong *)0x0;
                  goto LAB_23e2d0940;
                }
LAB_23e2d2a01:
                plVar13 = (longlong *)0x0;
                local_150 = (longlong *)0x0;
                plVar9 = (longlong *)0x0;
                plVar10 = (longlong *)0x0;
                local_158 = (longlong *)0x0;
                local_160 = (longlong *)0x0;
                pcVar18 = pcVar21;
                goto LAB_23e2d09e0;
              }
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
LAB_23e2d06bd:
              local_140 = _Py_NoneStruct_exref;
              *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
              lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
              plVar3 = *(longlong **)(lVar12 + 0x28);
              plVar9 = (longlong *)plVar3[2];
              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
              *(undefined4 *)(plVar3 + 8) = 0xffffffff;
              if (plVar9 != (longlong *)0x0) {
                plVar3[2] = 0;
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  (**(code **)(plVar9[1] + 0x30))();
                }
              }
              *plVar3 = *plVar3 + -1;
              if (*plVar3 == 0) {
                (**(code **)(plVar3[1] + 0x30))(plVar3);
              }
              plVar3[0xf] = 0;
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
LAB_23e2d0744:
              *plVar1 = *plVar1 + -1;
              if (*plVar1 != 0) {
                return local_140;
              }
              (**(code **)(plVar1[1] + 0x30))(plVar1);
              return local_140;
            }
            local_140 = *(code **)(param_1 + 0x60);
            pcVar21 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            local_148 = *(code **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          *plVar19 = *plVar19 + -1;
          if (*plVar19 == 0) {
            (**(code **)(plVar19[1] + 0x30))(plVar19);
            if (pcVar21 != (code *)0x0) {
              if (*(longlong **)(pcVar21 + 0x18) == plVar3) goto LAB_23e2d0e70;
LAB_23e2d2188:
              plVar13 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              plVar10 = (longlong *)0x0;
              local_150 = (longlong *)0x0;
              iVar24 = 0x1b3;
              local_158 = (longlong *)0x0;
              local_160 = (longlong *)0x0;
              goto LAB_23e2d0940;
            }
          }
          else if (pcVar21 != (code *)0x0) {
            if (plVar3 != *(longlong **)(pcVar21 + 0x18)) goto LAB_23e2d2188;
            goto LAB_23e2d0e70;
          }
          plVar13 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          local_150 = (longlong *)0x0;
          local_158 = (longlong *)0x0;
          local_160 = (longlong *)0x0;
          iVar8 = 0x1b3;
          goto LAB_23e2d1fb0;
        }
        local_140 = *(code **)(param_1 + 0x60);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        local_148 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (pcVar21 == (code *)0x0) {
          local_138 = _PyRuntime_exref;
          plVar13 = (longlong *)0x0;
          local_150 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          local_158 = (longlong *)0x0;
          local_160 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          iVar8 = 0x1b3;
          goto LAB_23e2d1fb0;
        }
        if (*(longlong **)(pcVar21 + 0x18) == plVar3) goto LAB_23e2d20e0;
        local_138 = _PyRuntime_exref;
        plVar13 = (longlong *)0x0;
        local_150 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        local_158 = (longlong *)0x0;
        iVar24 = 0x1b3;
        local_160 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
      }
    }
  }
LAB_23e2d0940:
  pcVar18 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar20 = *(code **)DAT_23ed6a4f8;
    *(undefined8 *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar20;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong **)(pcVar18 + 0x18) = plVar3;
  *plVar3 = *plVar3 + 1;
  lVar12 = *(longlong *)(local_138 + 0x1f8);
  *(int *)(pcVar18 + 0x24) = iVar24;
  *(undefined4 *)(pcVar18 + 0x20) = 0xffffffff;
  lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
  lVar14 = *(longlong *)(pcVar18 + -8);
  plVar19 = *(longlong **)(lVar12 + 8);
  *plVar19 = (longlong)(pcVar18 + -0x10);
  *(longlong *)(pcVar18 + -0x10) = lVar12;
  *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar14 & 3) | (ulonglong)plVar19;
  lVar14 = *(longlong *)pcVar21;
  *(code **)(lVar12 + 8) = pcVar18 + -0x10;
  *(code **)(pcVar18 + 0x10) = pcVar21;
  if (lVar14 == 0) {
    (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))(pcVar21);
  }
LAB_23e2d09e0:
  FUN_23e8bba40(plVar3,"ooooooooo",plVar1,plVar11,plVar10,plVar9,plVar13,local_160,local_158,
                local_150,0);
  if (_DAT_23eeb02a0 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eeb02a0 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar12 + 0x28);
  plVar19 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar19 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar19 = *plVar19 + -1;
    if (*plVar19 == 0) {
      (**(code **)(plVar19[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  plVar3[0xf] = 0;
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((local_160 != (longlong *)0x0) &&
     (lVar12 = *local_160, *local_160 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_160[1] + 0x30))(local_160);
  }
  if ((local_158 != (longlong *)0x0) &&
     (lVar12 = *local_158, *local_158 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_158[1] + 0x30))(local_158);
  }
  if ((local_150 != (longlong *)0x0) &&
     (lVar12 = *local_150, *local_150 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_150[1] + 0x30))(local_150);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,local_140,local_148,pcVar18);
  return (code *)0x0;
}
