/* ===== 23e7582c0 workers.fishing.fishing_bot:FishingBot._do_hooking ===== */
/* ghidra_name=FUN_23e7582c0 entry=23e7582c0 size=12598 */

code * FUN_23e7582c0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  undefined1 auVar5 [16];
  char cVar6;
  int iVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong lVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  code *pcVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  code *pcVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  longlong *local_e0;
  longlong *local_d8;
  longlong *local_d0;
  longlong *local_c8;
  longlong *local_c0;
  longlong *local_b8;
  longlong *local_88;
  longlong *plStack_80;
  undefined1 local_78 [16];
  longlong *local_68;
  
  plVar8 = DAT_23eedade8;
  plVar2 = (longlong *)*param_3;
  local_68 = (longlong *)0x0;
  local_78 = (undefined1  [16])0x0;
  if (DAT_23eedade8 == (longlong *)0x0) {
LAB_23e75831d:
    DAT_23eedade8 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eedaf90,DAT_23eedaeb8,0x60);
  }
  else {
    lVar12 = *DAT_23eedade8;
    if (1 < lVar12) {
      *DAT_23eedade8 = lVar12 + -1;
      goto LAB_23e75831d;
    }
    if (DAT_23eedade8[2] != 0) {
      *DAT_23eedade8 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e75831d;
    }
  }
  plVar3 = DAT_23eedade8;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar8 = DAT_23eedade8 + 9;
  lVar10 = *(longlong *)(lVar12 + 8);
  DAT_23eedade8[0xf] = lVar10;
  *(longlong **)(lVar12 + 8) = plVar8;
  if ((lVar10 != 0) &&
     (((*(char *)(lVar10 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar10 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar10 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar10 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar10 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar22 = DAT_23eed89b0;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar2,uVar22);
  if (plVar8 == (longlong *)0x0) {
    local_68 = *(longlong **)(param_1 + 0x70);
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plVar13 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar21 = (code *)0x0;
    plVar9 = (longlong *)0x0;
    uVar19 = 0x378;
    local_d0 = (longlong *)0x0;
    local_b8 = (longlong *)0x0;
    local_c8 = (longlong *)0x0;
    local_e0 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    local_d8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar8 = (longlong *)0x0;
    goto LAB_23e758dff;
  }
  *(undefined4 *)(plVar3 + 5) = 0x378;
  plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar8,DAT_23eed8d38);
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
    if (plVar9 == (longlong *)0x0) goto LAB_23e758b73;
LAB_23e7583ea:
    iVar7 = FUN_23a35f020(plVar9);
    lVar12 = *plVar9 + -1;
    if (iVar7 == -1) {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_68 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar9 = lVar12;
      if (lVar12 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      local_e0 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      local_d0 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      uVar19 = 0x378;
      pcVar21 = (code *)0x0;
      local_b8 = (longlong *)0x0;
      local_c8 = (longlong *)0x0;
      local_c0 = (longlong *)0x0;
      local_d8 = (longlong *)0x0;
      goto LAB_23e758dff;
    }
    *plVar9 = lVar12;
    if (lVar12 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    pcVar18 = _Py_NoneStruct_exref;
    if (iVar7 != 0) {
      lVar12 = *(longlong *)(param_1 + 0x38);
      lVar10 = *(longlong *)(lVar12 + 8);
      *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
      plVar8 = *(longlong **)(lVar10 + 0x28);
      plVar3 = (longlong *)plVar8[2];
      *(undefined8 *)(lVar12 + 8) = *(undefined8 *)(lVar10 + 0x30);
      *(undefined4 *)(plVar8 + 8) = 0xffffffff;
      if (plVar3 != (longlong *)0x0) {
        plVar8[2] = 0;
        *plVar3 = *plVar3 + -1;
        if (*plVar3 == 0) {
          (**(code **)(plVar3[1] + 0x30))();
        }
      }
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      plVar8[0xf] = 0;
LAB_23e758d12:
      *plVar2 = *plVar2 + -1;
      lVar12 = *plVar2;
joined_r0x00023e758d17:
      if (lVar12 != 0) {
        return pcVar18;
      }
      (**(code **)(plVar2[1] + 0x30))(plVar2);
      return pcVar18;
    }
    lVar10 = FUN_23e8e0ba0();
    lVar12 = DAT_23eed8c58;
    if (lVar10 == 0) {
      FUN_23e915740(param_1,local_78,DAT_23eed8c70);
LAB_23e7594d7:
      plVar8 = (longlong *)0x0;
      local_e0 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      local_d0 = (longlong *)0x0;
      pcVar21 = (code *)0x0;
      uVar19 = 0x37c;
      local_b8 = (longlong *)0x0;
      local_c8 = (longlong *)0x0;
      local_c0 = (longlong *)0x0;
      local_d8 = (longlong *)0x0;
    }
    else {
      *(undefined4 *)(plVar3 + 5) = 0x37c;
      plVar8 = (longlong *)
               FUN_23e915840(param_1,lVar10,DAT_23eed8d40,*(undefined8 *)(lVar12 + 0x18));
      if (plVar8 == (longlong *)0x0) {
        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_68 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e7594d7;
      }
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      plVar9 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eed8968);
      if (plVar9 == (longlong *)0x0) {
        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_68 = *(longlong **)(param_1 + 0x70);
        plVar13 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar21 = (code *)0x0;
        plVar8 = (longlong *)0x0;
        uVar19 = 0x37e;
        local_d0 = (longlong *)0x0;
        local_b8 = (longlong *)0x0;
        local_c8 = (longlong *)0x0;
        local_e0 = (longlong *)0x0;
        local_c0 = (longlong *)0x0;
        local_d8 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar9 = (longlong *)0x0;
      }
      else {
        *(undefined4 *)(plVar3 + 5) = 0x37e;
        plVar8 = (longlong *)FUN_23e91bfe0(param_1,plVar9,DAT_23eed9248);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        if (plVar8 == (longlong *)0x0) {
          local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          local_68 = *(longlong **)(param_1 + 0x70);
          plVar13 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcVar21 = (code *)0x0;
          plVar9 = (longlong *)0x0;
          uVar19 = 0x37e;
          local_d0 = (longlong *)0x0;
          local_b8 = (longlong *)0x0;
          local_c8 = (longlong *)0x0;
          local_e0 = (longlong *)0x0;
          local_c0 = (longlong *)0x0;
          local_d8 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        }
        else {
          plVar11 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eed8968);
          if (plVar11 == (longlong *)0x0) {
            local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
            local_68 = *(longlong **)(param_1 + 0x70);
            plVar13 = (longlong *)0x0;
            plVar11 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar9 = (longlong *)0x0;
            uVar19 = 0x37f;
            local_d0 = (longlong *)0x0;
            local_b8 = (longlong *)0x0;
            local_c8 = (longlong *)0x0;
            local_e0 = (longlong *)0x0;
            local_c0 = (longlong *)0x0;
            local_d8 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            pcVar21 = (code *)0x0;
          }
          else {
            *(undefined4 *)(plVar3 + 5) = 0x37f;
            plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar11,DAT_23eed9250);
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            if (plVar9 == (longlong *)0x0) {
              local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_68 = *(longlong **)(param_1 + 0x70);
              plVar13 = (longlong *)0x0;
              plVar11 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcVar21 = (code *)0x0;
              uVar19 = 0x37f;
              local_d0 = (longlong *)0x0;
              local_b8 = (longlong *)0x0;
              local_c8 = (longlong *)0x0;
              local_e0 = (longlong *)0x0;
              local_c0 = (longlong *)0x0;
              local_d8 = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
            else {
              plVar11 = (longlong *)FUN_23e8bd600(param_1,plVar8);
              if (plVar11 == (longlong *)0x0) {
LAB_23e759690:
                pcVar21 = (code *)0x0;
                local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                local_68 = *(longlong **)(param_1 + 0x70);
                plVar13 = (longlong *)0x0;
                plVar11 = (longlong *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar19 = 0x380;
                local_d0 = (longlong *)0x0;
                local_b8 = (longlong *)0x0;
                local_c8 = (longlong *)0x0;
                local_e0 = (longlong *)0x0;
                local_c0 = (longlong *)0x0;
                local_d8 = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              }
              else {
                lVar12 = *plVar11 + -1;
                *plVar11 = lVar12;
                if (plVar11[2] == 0) {
                  pcVar21 = _Py_TrueStruct_exref;
                  if (lVar12 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                    pcVar21 = _Py_TrueStruct_exref;
                  }
                }
                else {
                  pcVar21 = _Py_FalseStruct_exref;
                  if (lVar12 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                    pcVar21 = _Py_FalseStruct_exref;
                  }
                }
                iVar7 = FUN_23a35f020(pcVar21);
                if (iVar7 == 1) {
                  plVar11 = (longlong *)FUN_23e8bd600(param_1,plVar9);
                  if (plVar11 == (longlong *)0x0) goto LAB_23e759690;
                  lVar12 = plVar11[2];
                  lVar10 = *plVar11 + -1;
                  *plVar11 = lVar10;
                  if (lVar12 == 0) {
                    if (lVar10 == 0) {
                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                    }
                  }
                  else {
                    if (lVar10 == 0) {
                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                    }
                    pcVar21 = _Py_TrueStruct_exref;
                    if (0 < lVar12) goto LAB_23e75855a;
                  }
                  pcVar21 = _Py_FalseStruct_exref;
                }
LAB_23e75855a:
                lVar10 = DAT_23eed8950;
                *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
                lVar12 = *(longlong *)(lVar10 + 0x20);
                if (*(char *)(lVar12 + 10) == '\0') {
                  plVar11 = (longlong *)FUN_23a37a020(lVar10,DAT_23eed9258);
                  if (plVar11 == (longlong *)0x0) goto LAB_23e759370;
                  lVar10 = *plVar11;
LAB_23e759364:
                  if (lVar10 == 0) goto LAB_23e759370;
                }
                else {
                  iVar7 = *(int *)(lVar12 + 0xc);
                  if (*(int *)(lVar12 + 0xc) == 0) {
                    *(int *)(lVar12 + 0xc) = DAT_23ec1545c;
                    iVar7 = DAT_23ec1545c;
                    DAT_23ec1545c = DAT_23ec1545c + 1;
                  }
                  if (DAT_23ec15428 != iVar7) {
                    DAT_23ec15428 = iVar7;
                    DAT_23eedadd8 =
                         FUN_23e8cbd60(lVar12,DAT_23eed9258,*(undefined8 *)(DAT_23eed9258 + 0x18));
                  }
                  if (-1 < DAT_23eedadd8) {
                    lVar1 = lVar12 + 0x20 + (1L << (*(byte *)(lVar12 + 9) & 0x3f));
                    lVar10 = *(longlong *)(lVar1 + 8 + DAT_23eedadd8 * 0x10);
                    if (lVar10 != 0) goto LAB_23e7585d0;
                    DAT_23eedadd8 =
                         FUN_23e8cbd60(lVar12,DAT_23eed9258,*(undefined8 *)(DAT_23eed9258 + 0x18));
                    if (-1 < DAT_23eedadd8) {
                      lVar10 = *(longlong *)(lVar1 + 8 + DAT_23eedadd8 * 0x10);
                      goto LAB_23e759364;
                    }
                  }
LAB_23e759370:
                  plVar11 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eed9258);
                  if ((plVar11 == (longlong *)0x0) || (lVar10 = *plVar11, lVar10 == 0)) {
                    plVar13 = (longlong *)0x0;
                    plVar11 = (longlong *)0x0;
                    FUN_23e915740(param_1,local_78,DAT_23eed9258);
                    local_d0 = (longlong *)0x0;
                    uVar19 = 0x382;
                    local_b8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_e0 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    local_d8 = (longlong *)0x0;
                    goto LAB_23e758dff;
                  }
                }
LAB_23e7585d0:
                plVar11 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eed8aa8);
                if (plVar11 == (longlong *)0x0) {
                  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_68 = *(longlong **)(param_1 + 0x70);
                  plVar13 = (longlong *)0x0;
                  plVar11 = (longlong *)0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar19 = 0x382;
                  local_d0 = (longlong *)0x0;
                  local_b8 = (longlong *)0x0;
                  local_c8 = (longlong *)0x0;
                  local_e0 = (longlong *)0x0;
                  local_d8 = (longlong *)0x0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  local_c0 = (longlong *)0x0;
                }
                else {
                  local_d8 = (longlong *)FUN_23a38cc10(param_1,lVar10,plVar11);
                  lVar12 = *plVar11;
                  *plVar11 = lVar12 + -1;
                  if (lVar12 + -1 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  if (local_d8 == (longlong *)0x0) {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    plVar13 = (longlong *)0x0;
                    plVar11 = (longlong *)0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar19 = 0x382;
                    local_d0 = (longlong *)0x0;
                    local_b8 = (longlong *)0x0;
                    local_c8 = (longlong *)0x0;
                    local_e0 = (longlong *)0x0;
                    local_c0 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                  else {
                    lVar12 = *(longlong *)(DAT_23eed8950 + 0x20);
                    if (*(char *)(lVar12 + 10) == '\0') {
                      plVar11 = (longlong *)FUN_23a37a020(DAT_23eed8950,DAT_23eed9260);
                      if (plVar11 == (longlong *)0x0) goto LAB_23e759600;
                      lVar10 = *plVar11;
LAB_23e7595f5:
                      if (lVar10 == 0) goto LAB_23e759600;
                    }
                    else {
                      iVar7 = *(int *)(lVar12 + 0xc);
                      if (*(int *)(lVar12 + 0xc) == 0) {
                        *(int *)(lVar12 + 0xc) = DAT_23ec1545c;
                        iVar7 = DAT_23ec1545c;
                        DAT_23ec1545c = DAT_23ec1545c + 1;
                      }
                      if (DAT_23ec1542c != iVar7) {
                        DAT_23ec1542c = iVar7;
                        DAT_23eedade0 =
                             FUN_23e8cbd60(lVar12,DAT_23eed9260,
                                           *(undefined8 *)(DAT_23eed9260 + 0x18));
                      }
                      if (-1 < DAT_23eedade0) {
                        lVar1 = lVar12 + 0x20 + (1L << (*(byte *)(lVar12 + 9) & 0x3f));
                        lVar10 = *(longlong *)(lVar1 + 8 + DAT_23eedade0 * 0x10);
                        if (lVar10 != 0) goto LAB_23e7586a4;
                        DAT_23eedade0 =
                             FUN_23e8cbd60(lVar12,DAT_23eed9260,
                                           *(undefined8 *)(DAT_23eed9260 + 0x18));
                        if (-1 < DAT_23eedade0) {
                          lVar10 = *(longlong *)(lVar1 + 8 + DAT_23eedade0 * 0x10);
                          goto LAB_23e7595f5;
                        }
                      }
LAB_23e759600:
                      plVar11 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eed9260);
                      if ((plVar11 == (longlong *)0x0) || (lVar10 = *plVar11, lVar10 == 0)) {
                        plVar13 = (longlong *)0x0;
                        plVar11 = (longlong *)0x0;
                        FUN_23e915740(param_1,local_78,DAT_23eed9260);
                        local_d0 = (longlong *)0x0;
                        uVar19 = 899;
                        local_b8 = (longlong *)0x0;
                        local_c8 = (longlong *)0x0;
                        local_e0 = (longlong *)0x0;
                        local_c0 = (longlong *)0x0;
                        goto LAB_23e758dff;
                      }
                    }
LAB_23e7586a4:
                    plVar11 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eed8aa8);
                    if (plVar11 == (longlong *)0x0) {
                      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_68 = *(longlong **)(param_1 + 0x70);
                      local_d0 = (longlong *)0x0;
                      plVar13 = (longlong *)0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar19 = 899;
                      local_b8 = (longlong *)0x0;
                      local_c8 = (longlong *)0x0;
                      local_e0 = (longlong *)0x0;
                      local_c0 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      plVar11 = (longlong *)0x0;
                    }
                    else {
                      local_c0 = (longlong *)FUN_23a38cc10(param_1,lVar10,plVar11);
                      *plVar11 = *plVar11 + -1;
                      if (*plVar11 == 0) {
                        (**(code **)(plVar11[1] + 0x30))(plVar11);
                      }
                      if (local_c0 == (longlong *)0x0) {
                        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                        local_68 = *(longlong **)(param_1 + 0x70);
                        plVar13 = (longlong *)0x0;
                        plVar11 = (longlong *)0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uVar19 = 899;
                        local_d0 = (longlong *)0x0;
                        local_b8 = (longlong *)0x0;
                        local_c8 = (longlong *)0x0;
                        local_e0 = (longlong *)0x0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      }
                      else {
                        plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eed8af8);
                        plVar11 = (longlong *)0x0;
                        if (plVar13 == (longlong *)0x0) {
LAB_23e759950:
                          local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                          local_68 = *(longlong **)(param_1 + 0x70);
                          local_d0 = (longlong *)0x0;
                          plVar13 = (longlong *)0x0;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          uVar19 = 0x386;
                          local_b8 = (longlong *)0x0;
                          local_c8 = (longlong *)0x0;
                          local_e0 = (longlong *)0x0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        }
                        else {
                          plVar14 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23eed9268);
                          *plVar13 = *plVar13 + -1;
                          if (*plVar13 == 0) {
                            (**(code **)(plVar13[1] + 0x30))(plVar13);
                          }
                          lVar12 = DAT_23eed9270;
                          if (plVar14 == (longlong *)0x0) {
                            local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                            local_68 = *(longlong **)(param_1 + 0x70);
                            local_d0 = (longlong *)0x0;
                            plVar11 = (longlong *)0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            uVar19 = 0x386;
                            local_b8 = (longlong *)0x0;
                            local_c8 = (longlong *)0x0;
                            local_e0 = (longlong *)0x0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            plVar13 = (longlong *)0x0;
                          }
                          else {
                            *(undefined4 *)(plVar3 + 5) = 0x386;
                            plVar11 = (longlong *)
                                      FUN_23e9186b0(param_1,plVar14,lVar12 + 0x18,DAT_23eed8ce8);
                            *plVar14 = *plVar14 + -1;
                            if (*plVar14 == 0) {
                              (**(code **)(plVar14[1] + 0x30))(plVar14);
                            }
                            if (plVar11 == (longlong *)0x0) goto LAB_23e759950;
                            iVar7 = FUN_23a35f020(plVar11);
                            if (iVar7 == -1) {
LAB_23e75a60d:
                              local_68 = *(longlong **)(param_1 + 0x70);
                              local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                              uVar19 = 0x388;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e75a63c:
                              local_d0 = (longlong *)0x0;
                              plVar13 = (longlong *)0x0;
                              local_b8 = (longlong *)0x0;
                              local_c8 = (longlong *)0x0;
                              local_e0 = (longlong *)0x0;
                            }
                            else if (iVar7 == 0) {
LAB_23e75879d:
                              iVar7 = FUN_23a35f020(pcVar21);
                              lVar10 = DAT_23eed92d8;
                              lVar12 = DAT_23eed92d0;
                              uVar22 = DAT_23eed8b40;
                              if (iVar7 == -1) {
                                local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                local_68 = *(longlong **)(param_1 + 0x70);
                                uVar19 = 0x39c;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                goto LAB_23e75a63c;
                              }
                              if (iVar7 == 0) {
                                *(undefined4 *)(plVar3 + 5) = 0x3a1;
                                plVar13 = (longlong *)
                                          FUN_23e915840(param_1,plVar2,uVar22,
                                                        *(undefined8 *)(lVar10 + 0x18));
                                if (plVar13 == (longlong *)0x0) {
                                  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                  local_68 = *(longlong **)(param_1 + 0x70);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  local_d0 = (longlong *)0x0;
                                  local_b8 = (longlong *)0x0;
                                  local_c8 = (longlong *)0x0;
                                  local_e0 = (longlong *)0x0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  plVar13 = (longlong *)0x0;
                                  uVar19 = 0x3a1;
                                }
                                else {
LAB_23e7588d7:
                                  *plVar13 = *plVar13 + -1;
                                  if (*plVar13 == 0) {
                                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                                  }
                                  local_d0 = (longlong *)0x0;
                                  plVar13 = (longlong *)0x0;
                                  local_b8 = (longlong *)0x0;
                                  local_c8 = (longlong *)0x0;
                                  local_e0 = (longlong *)0x0;
LAB_23e758917:
                                  lVar12 = FUN_23e8e0e20();
                                  if (lVar12 == 0) {
                                    FUN_23e915740(param_1,local_78,DAT_23eed8988);
                                    uVar19 = 0x3a3;
                                  }
                                  else {
                                    plVar14 = (longlong *)FUN_23e8bc2f0(lVar12,DAT_23eed8990);
                                    if (plVar14 != (longlong *)0x0) {
                                      cVar6 = FUN_23e8d9ac0(plVar2,DAT_23eed8998,plVar14);
                                      *plVar14 = *plVar14 + -1;
                                      if (*plVar14 == 0) {
                                        (**(code **)(plVar14[1] + 0x30))(plVar14);
                                      }
                                      if (cVar6 != '\0') {
                                        lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                                        plVar3 = *(longlong **)(lVar12 + 0x28);
                                        plVar14 = (longlong *)plVar3[2];
                                        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                                             *(undefined8 *)(lVar12 + 0x30);
                                        *(undefined4 *)(plVar3 + 8) = 0xffffffff;
                                        if (plVar14 != (longlong *)0x0) {
                                          plVar3[2] = 0;
                                          *plVar14 = *plVar14 + -1;
                                          if (*plVar14 == 0) {
                                            (**(code **)(plVar14[1] + 0x30))();
                                          }
                                        }
                                        *plVar3 = *plVar3 + -1;
                                        if (*plVar3 == 0) {
                                          (**(code **)(plVar3[1] + 0x30))(plVar3);
                                        }
                                        plVar3[0xf] = 0;
                                        pcVar18 = _Py_NoneStruct_exref;
                                        *(longlong *)_Py_NoneStruct_exref =
                                             *(longlong *)_Py_NoneStruct_exref + 1;
                                        *plVar8 = *plVar8 + -1;
                                        if (*plVar8 == 0) {
                                          (**(code **)(plVar8[1] + 0x30))(plVar8);
                                        }
                                        *plVar9 = *plVar9 + -1;
                                        if (*plVar9 == 0) {
                                          (**(code **)(plVar9[1] + 0x30))(plVar9);
                                        }
                                        *(longlong *)pcVar21 = *(longlong *)pcVar21 + -1;
                                        if (*(longlong *)pcVar21 == 0) {
                                          (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))(pcVar21);
                                        }
                                        lVar12 = *local_d8;
                                        *local_d8 = lVar12 + -1;
                                        if (lVar12 + -1 == 0) {
                                          (**(code **)(local_d8[1] + 0x30))(local_d8);
                                        }
                                        lVar12 = *local_c0;
                                        *local_c0 = lVar12 + -1;
                                        if (lVar12 + -1 == 0) {
                                          (**(code **)(local_c0[1] + 0x30))();
                                        }
                                        *plVar11 = *plVar11 + -1;
                                        if (*plVar11 == 0) {
                                          (**(code **)(plVar11[1] + 0x30))(plVar11);
                                        }
                                        if ((plVar13 != (longlong *)0x0) &&
                                           (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
                                          (**(code **)(plVar13[1] + 0x30))(plVar13);
                                        }
                                        if ((local_e0 != (longlong *)0x0) &&
                                           (lVar12 = *local_e0, *local_e0 = lVar12 + -1,
                                           lVar12 + -1 == 0)) {
                                          (**(code **)(local_e0[1] + 0x30))(local_e0);
                                        }
                                        if ((local_c8 != (longlong *)0x0) &&
                                           (lVar12 = *local_c8, *local_c8 = lVar12 + -1,
                                           lVar12 + -1 == 0)) {
                                          (**(code **)(local_c8[1] + 0x30))();
                                        }
                                        if ((local_b8 != (longlong *)0x0) &&
                                           (lVar12 = *local_b8, *local_b8 = lVar12 + -1,
                                           lVar12 + -1 == 0)) {
                                          (**(code **)(local_b8[1] + 0x30))(local_b8);
                                        }
                                        if ((local_d0 != (longlong *)0x0) &&
                                           (lVar12 = *local_d0, *local_d0 = lVar12 + -1,
                                           lVar12 + -1 == 0)) {
                                          (**(code **)(local_d0[1] + 0x30))(local_d0);
                                          *plVar2 = *plVar2 + -1;
                                          lVar12 = *plVar2;
                                          goto joined_r0x00023e758d17;
                                        }
                                        goto LAB_23e758d12;
                                      }
                                    }
                                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                    local_68 = *(longlong **)(param_1 + 0x70);
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    uVar19 = 0x3a3;
                                  }
                                }
                              }
                              else {
                                *(undefined4 *)(plVar3 + 5) = 0x39d;
                                plVar13 = (longlong *)
                                          FUN_23e915840(param_1,plVar2,uVar22,
                                                        *(undefined8 *)(lVar12 + 0x18));
                                if (plVar13 == (longlong *)0x0) {
                                  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                  local_68 = *(longlong **)(param_1 + 0x70);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  local_d0 = (longlong *)0x0;
                                  local_b8 = (longlong *)0x0;
                                  local_c8 = (longlong *)0x0;
                                  local_e0 = (longlong *)0x0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  plVar13 = (longlong *)0x0;
                                  uVar19 = 0x39d;
                                }
                                else {
                                  *plVar13 = *plVar13 + -1;
                                  if (*plVar13 == 0) {
                                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                                  }
                                  plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eed8a98);
                                  if (plVar13 == (longlong *)0x0) {
                                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                    local_68 = *(longlong **)(param_1 + 0x70);
                                    plVar13 = (longlong *)0x0;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    local_d0 = (longlong *)0x0;
                                    local_b8 = (longlong *)0x0;
                                    local_c8 = (longlong *)0x0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    local_e0 = (longlong *)0x0;
                                    uVar19 = 0x39e;
                                  }
                                  else {
                                    plVar14 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23eed92c0);
                                    lVar12 = *plVar13;
                                    *plVar13 = lVar12 + -1;
                                    if (lVar12 + -1 == 0) {
                                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                                    }
                                    if (plVar14 != (longlong *)0x0) {
                                      *local_c0 = *local_c0 + 1;
                                      local_88 = plVar14;
                                      plStack_80 = local_c0;
                                      plVar13 = (longlong *)FUN_23ab01810(param_1,&local_88);
                                      if (plVar13 != (longlong *)0x0) {
                                        *plVar13 = *plVar13 + -1;
                                        if (*plVar13 == 0) {
                                          (**(code **)(plVar13[1] + 0x30))(plVar13);
                                        }
                                        lVar12 = FUN_23e8e0ba0();
                                        if (lVar12 == 0) {
                                          FUN_23e915740(param_1,local_78);
                                        }
                                        else {
                                          *(undefined4 *)(plVar3 + 5) = 0x39f;
                                          plVar13 = (longlong *)FUN_23e915840(param_1,lVar12);
                                          if (plVar13 != (longlong *)0x0) goto LAB_23e7588d7;
                                          local_68 = *(longlong **)(param_1 + 0x70);
                                          local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                        }
                                        plVar13 = (longlong *)0x0;
                                        local_d0 = (longlong *)0x0;
                                        local_b8 = (longlong *)0x0;
                                        local_c8 = (longlong *)0x0;
                                        local_e0 = (longlong *)0x0;
                                        uVar19 = 0x39f;
                                        goto LAB_23e758dff;
                                      }
                                    }
                                    plVar13 = (longlong *)0x0;
                                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                    local_68 = *(longlong **)(param_1 + 0x70);
                                    local_d0 = (longlong *)0x0;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    local_b8 = (longlong *)0x0;
                                    local_c8 = (longlong *)0x0;
                                    local_e0 = (longlong *)0x0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    uVar19 = 0x39e;
                                  }
                                }
                              }
                            }
                            else {
                              plVar13 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eed89b0);
                              if (plVar13 == (longlong *)0x0) {
                                local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                local_68 = *(longlong **)(param_1 + 0x70);
                                local_d0 = (longlong *)0x0;
                                uVar19 = 0x388;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                local_b8 = (longlong *)0x0;
                                local_c8 = (longlong *)0x0;
                                local_e0 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plVar13 = (longlong *)0x0;
                              }
                              else {
                                *(undefined4 *)(plVar3 + 5) = 0x388;
                                plVar14 = (longlong *)FUN_23e91bfe0(param_1,plVar13,DAT_23eed8d38);
                                *plVar13 = *plVar13 + -1;
                                if (*plVar13 == 0) {
                                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                                }
                                if (plVar14 != (longlong *)0x0) {
                                  iVar7 = FUN_23a35f020(plVar14);
                                  lVar12 = *plVar14;
                                  *plVar14 = lVar12 + -1;
                                  if (lVar12 + -1 == 0) {
                                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                                  }
                                  if (iVar7 == -1) goto LAB_23e75a60d;
                                  if (iVar7 != 0) goto LAB_23e75879d;
                                  plVar14 = (longlong *)FUN_23a388310(plVar11);
                                  if (plVar14 == (longlong *)0x0) {
                                    uVar22 = *(undefined8 *)(param_1 + 0x60);
                                    uVar23 = *(undefined8 *)(param_1 + 0x68);
                                    plVar15 = *(longlong **)(param_1 + 0x70);
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  }
                                  else {
                                    plVar13 = (longlong *)(**(code **)(plVar14[1] + 0xe0))(plVar14);
                                    if ((plVar13 == (longlong *)0x0) &&
                                       (plVar13 = (longlong *)FUN_23a3c1b70(param_1,local_78,0),
                                       plVar13 == (longlong *)0x0)) {
                                      local_c8 = (longlong *)0x0;
                                      local_e0 = (longlong *)0x0;
                                    }
                                    else {
                                      local_e0 = (longlong *)
                                                 (**(code **)(plVar14[1] + 0xe0))(plVar14);
                                      if ((local_e0 == (longlong *)0x0) &&
                                         (local_e0 = (longlong *)FUN_23a3c1b70(param_1,local_78,1,3)
                                         , local_e0 == (longlong *)0x0)) {
                                        local_c8 = (longlong *)0x0;
                                      }
                                      else {
                                        local_c8 = (longlong *)
                                                   (**(code **)(plVar14[1] + 0xe0))(plVar14);
                                        if (((local_c8 != (longlong *)0x0) ||
                                            (local_c8 = (longlong *)
                                                        FUN_23a3c1b70(param_1,local_78,2,3),
                                            local_c8 != (longlong *)0x0)) &&
                                           (cVar6 = FUN_23a3884a0(param_1,local_78,plVar14,3),
                                           cVar6 != '\0')) {
                                          *plVar14 = *plVar14 + -1;
                                          if (*plVar14 == 0) {
                                            (**(code **)(plVar14[1] + 0x30))(plVar14);
                                          }
                                          if (*plVar13 == 0) {
                                            (**(code **)(plVar13[1] + 0x30))(plVar13);
                                          }
                                          if (*local_e0 == 0) {
                                            (**(code **)(local_e0[1] + 0x30))();
                                          }
                                          if (*local_c8 == 0) {
                                            (**(code **)(local_c8[1] + 0x30))();
                                          }
                                          plVar15 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eed8b40);
                                          plVar14 = DAT_23eed9278;
                                          if (plVar15 == (longlong *)0x0) {
                                            local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                            local_68 = *(longlong **)(param_1 + 0x70);
                                            uVar19 = 0x38a;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            local_b8 = (longlong *)0x0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            local_d0 = (longlong *)0x0;
                                            goto LAB_23e758dff;
                                          }
                                          lVar12 = *(longlong *)(param_1 + 0x10);
                                          plVar16 = *(longlong **)(lVar12 + 0xe38);
                                          if (plVar16 == (longlong *)0x0) {
                                            plVar16 = (longlong *)
                                                      FUN_23e916a20(PyTuple_Type_exref,5);
                                          }
                                          else {
                                            lVar10 = plVar16[3];
                                            *(int *)(lVar12 + 0xec8) = *(int *)(lVar12 + 0xec8) + -1
                                            ;
                                            *(longlong *)(lVar12 + 0xe38) = lVar10;
                                            *plVar16 = 1;
                                          }
                                          pcVar18 = _PyRuntime_exref;
                                          *(undefined1 (*) [16])(plVar16 + 4) =
                                               (undefined1  [16])0x0;
                                          lVar12 = *(longlong *)(pcVar18 + 0x1f8);
                                          *(undefined1 (*) [16])(plVar16 + 6) =
                                               (undefined1  [16])0x0;
                                          lVar12 = *(longlong *)
                                                    (*(longlong *)(lVar12 + 0x10) + 0x2e8);
                                          lVar10 = plVar16[-1];
                                          puVar4 = *(undefined8 **)(lVar12 + 8);
                                          *puVar4 = plVar16 + -2;
                                          plVar16[-2] = lVar12;
                                          plVar16[-1] = (ulonglong)((uint)lVar10 & 3) |
                                                        (ulonglong)puVar4;
                                          *(longlong **)(lVar12 + 8) = plVar16 + -2;
                                          *plVar14 = *plVar14 + 1;
                                          plVar16[3] = (longlong)plVar14;
                                          plVar14 = DAT_23ed6cd28;
                                          if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                            plVar17 = (longlong *)
                                                      PyDict_GetItemString(DAT_23ed6ccc0,"format");
                                            if (plVar17 != (longlong *)0x0) {
                                              *plVar17 = *plVar17 + 1;
                                              DAT_23ed6a4c0 = plVar17;
                                              goto LAB_23e759d0b;
                                            }
LAB_23e75b151:
                                            PyErr_PrintEx(0);
                                            Py_Exit(1);
LAB_23e75b164:
                                            local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                            local_68 = *(longlong **)(param_1 + 0x70);
                                            uVar19 = 0x38a;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            local_d0 = (longlong *)0x0;
                                            local_b8 = (longlong *)0x0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            goto LAB_23e758dff;
                                          }
LAB_23e759d0b:
                                          local_88 = local_e0;
                                          plStack_80 = plVar14;
                                          lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_88);
                                          if (lVar12 != 0) {
                                            plVar16[4] = lVar12;
                                            plVar14 = DAT_23eed9280;
                                            *DAT_23eed9280 = *DAT_23eed9280 + 1;
                                            plVar16[5] = (longlong)plVar14;
                                            plVar14 = DAT_23ed6cd28;
                                            if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                              plVar17 = (longlong *)
                                                        PyDict_GetItemString(DAT_23ed6ccc0,"format")
                                              ;
                                              if (plVar17 == (longlong *)0x0) goto LAB_23e75b151;
                                              *plVar17 = *plVar17 + 1;
                                              DAT_23ed6a4c0 = plVar17;
                                            }
                                            local_88 = local_c8;
                                            plStack_80 = plVar14;
                                            lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_88);
                                            if (lVar12 != 0) {
                                              plVar16[6] = lVar12;
                                              plVar14 = DAT_23eed9288;
                                              *DAT_23eed9288 = *DAT_23eed9288 + 1;
                                              plVar16[7] = (longlong)plVar14;
                                              plVar14 = (longlong *)
                                                        PyUnicode_Join(DAT_23ed6cd28,plVar16);
                                              *plVar16 = *plVar16 + -1;
                                              if (*plVar16 == 0) {
                                                FUN_23a334bc0(plVar16);
                                              }
                                              if (plVar14 == (longlong *)0x0) {
                                                local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                                local_68 = *(longlong **)(param_1 + 0x70);
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                lVar12 = *plVar15;
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                                *plVar15 = lVar12 + -1;
                                                local_b8 = (longlong *)0x0;
                                                if (lVar12 + -1 == 0) {
                                                  FUN_23a334bc0();
                                                  uVar19 = 0x38a;
                                                  local_d0 = (longlong *)0x0;
                                                }
                                                else {
                                                  uVar19 = 0x38a;
                                                  local_d0 = (longlong *)0x0;
                                                }
                                              }
                                              else {
                                                *(undefined4 *)(plVar3 + 5) = 0x38a;
                                                plVar16 = (longlong *)FUN_23e914090(param_1,plVar15)
                                                ;
                                                lVar12 = *plVar15;
                                                *plVar15 = lVar12 + -1;
                                                if (lVar12 + -1 == 0) {
                                                  FUN_23a334bc0();
                                                }
                                                lVar12 = *plVar14;
                                                *plVar14 = lVar12 + -1;
                                                if (lVar12 + -1 == 0) {
                                                  FUN_23a334bc0();
                                                }
                                                if (plVar16 == (longlong *)0x0) goto LAB_23e75b164;
                                                *plVar16 = *plVar16 + -1;
                                                if (*plVar16 == 0) {
                                                  FUN_23a334bc0(plVar16);
                                                }
                                                local_b8 = (longlong *)
                                                           FUN_23e8bc2f0(plVar2,DAT_23eed8a60);
                                                if (local_b8 == (longlong *)0x0) {
                                                  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                                  local_68 = *(longlong **)(param_1 + 0x70);
                                                  uVar19 = 0x38d;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  local_d0 = (longlong *)0x0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  local_b8 = (longlong *)0x0;
                                                }
                                                else {
                                                  local_88 = local_b8;
                                                  cVar6 = FUN_23e8c72f0(&local_88,DAT_23ed6ccf8);
                                                  plVar14 = local_88;
                                                  if (cVar6 != '\0') {
                                                    local_b8 = local_88;
                                                    cVar6 = FUN_23e8d9ac0(plVar2,DAT_23eed8a60);
                                                    if (cVar6 != '\0') {
                                                      lVar12 = *plVar14;
                                                      *plVar14 = lVar12 + -1;
                                                      if (lVar12 + -1 == 0) {
                                                        FUN_23a334bc0(plVar14);
                                                      }
                                                      *(undefined4 *)(plVar3 + 5) = 0x38e;
                                                      local_b8 = (longlong *)
                                                                 FUN_23e91bfe0(param_1,plVar2,
                                                                               DAT_23eed9290);
                                                      if (local_b8 == (longlong *)0x0) {
                                                        local_78 = *(undefined1 (*) [16])
                                                                    (param_1 + 0x60);
                                                        local_68 = *(longlong **)(param_1 + 0x70);
                                                        uVar19 = 0x38e;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        local_d0 = (longlong *)0x0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                      }
                                                      else {
                                                        lVar12 = FUN_23e8e07b0();
                                                        if (lVar12 == 0) {
                                                          FUN_23e915740(param_1,local_78,
                                                                        DAT_23eed8f68);
                                                          uVar19 = 0x38f;
                                                          local_d0 = (longlong *)0x0;
                                                        }
                                                        else {
                                                          *(undefined4 *)(plVar3 + 5) = 0x38f;
                                                          local_d0 = (longlong *)
                                                                     FUN_23e91a870(param_1,lVar12);
                                                          if (local_d0 == (longlong *)0x0) {
                                                            local_78 = *(undefined1 (*) [16])
                                                                        (param_1 + 0x60);
                                                            local_68 = *(longlong **)
                                                                        (param_1 + 0x70);
                                                            uVar19 = 0x38f;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                          }
                                                          else {
                                                            plVar14 = (longlong *)
                                                                      FUN_23e8bc2f0(local_d0,
                                                  DAT_23eed9298);
                                                  if (plVar14 == (longlong *)0x0) {
LAB_23e75b0b3:
                                                    local_78 = *(undefined1 (*) [16])
                                                                (param_1 + 0x60);
                                                    local_68 = *(longlong **)(param_1 + 0x70);
                                                    uVar19 = 0x390;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                  }
                                                  else {
                                                    lVar12 = FUN_23e94f9d0(param_1,local_e0,
                                                                           DAT_23ed6cd28);
                                                    if (lVar12 == 0) {
LAB_23e75b057:
                                                      local_78 = *(undefined1 (*) [16])
                                                                  (param_1 + 0x60);
                                                      local_68 = *(longlong **)(param_1 + 0x70);
                                                      uVar19 = 0x390;
                                                      uVar20 = 0x390;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      *plVar14 = *plVar14 + -1;
                                                      lVar12 = *plVar14;
joined_r0x00023e75b088:
                                                      if (lVar12 == 0) {
LAB_23e75b08e:
                                                        FUN_23a334bc0(plVar14);
                                                        uVar19 = uVar20;
                                                      }
                                                    }
                                                    else {
                                                      plVar16 = (longlong *)
                                                                FUN_23e916ad0(*(undefined8 *)
                                                                               (param_1 + 0x10),4);
                                                      plVar16[3] = lVar12;
                                                      plVar15 = DAT_23eed92a0;
                                                      *DAT_23eed92a0 = *DAT_23eed92a0 + 1;
                                                      plVar16[4] = (longlong)plVar15;
                                                      lVar12 = FUN_23e94f9d0(param_1,local_c8,
                                                                             DAT_23ed6cd28);
                                                      if (lVar12 == 0) {
                                                        local_78 = *(undefined1 (*) [16])
                                                                    (param_1 + 0x60);
                                                        local_68 = *(longlong **)(param_1 + 0x70);
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        *plVar14 = *plVar14 + -1;
                                                        if (*plVar14 == 0) {
                                                          FUN_23a334bc0(plVar14);
                                                        }
                                                        *plVar16 = *plVar16 + -1;
                                                        if (*plVar16 == 0) {
                                                          FUN_23a334bc0(plVar16);
                                                        }
                                                        uVar19 = 0x390;
                                                      }
                                                      else {
                                                        plVar16[5] = lVar12;
                                                        plVar15 = DAT_23eed92a8;
                                                        *DAT_23eed92a8 = *DAT_23eed92a8 + 1;
                                                        plVar16[6] = (longlong)plVar15;
                                                        plVar15 = (longlong *)
                                                                  PyUnicode_Join(DAT_23ed6cd28,
                                                                                 plVar16);
                                                        *plVar16 = *plVar16 + -1;
                                                        if (*plVar16 == 0) {
                                                          FUN_23a334bc0(plVar16);
                                                        }
                                                        if (plVar15 == (longlong *)0x0)
                                                        goto LAB_23e75b057;
                                                        *(undefined4 *)(plVar3 + 5) = 0x390;
                                                        local_88 = plVar15;
                                                        plStack_80 = local_b8;
                                                        plVar16 = (longlong *)
                                                                  FUN_23e94ed00(param_1,plVar14);
                                                        *plVar14 = *plVar14 + -1;
                                                        if (*plVar14 == 0) {
                                                          FUN_23a334bc0(plVar14);
                                                        }
                                                        *plVar15 = *plVar15 + -1;
                                                        if (*plVar15 == 0) {
                                                          FUN_23a334bc0(plVar15);
                                                        }
                                                        if (plVar16 == (longlong *)0x0)
                                                        goto LAB_23e75b0b3;
                                                        *plVar16 = *plVar16 + -1;
                                                        if (*plVar16 == 0) {
                                                          FUN_23a334bc0(plVar16);
                                                        }
                                                        iVar7 = PySequence_Contains(plVar9,plVar13);
                                                        if (iVar7 == -1) {
LAB_23e75b2bb:
                                                          local_78 = *(undefined1 (*) [16])
                                                                      (param_1 + 0x60);
                                                          local_68 = *(longlong **)(param_1 + 0x70);
                                                          uVar19 = 0x393;
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          goto LAB_23e758dff;
                                                        }
                                                        if (iVar7 == 1) {
LAB_23e75a1db:
                                                          plVar14 = (longlong *)
                                                                    FUN_23e8bc2f0(plVar2,
                                                  DAT_23eed8b40);
                                                  plVar15 = DAT_23eed92b0;
                                                  if (plVar14 == (longlong *)0x0) {
LAB_23e75b349:
                                                    local_78 = *(undefined1 (*) [16])
                                                                (param_1 + 0x60);
                                                    local_68 = *(longlong **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    uVar19 = 0x394;
                                                  }
                                                  else {
                                                    plVar16 = (longlong *)
                                                              FUN_23e916ad0(*(undefined8 *)
                                                                             (param_1 + 0x10),3);
                                                    *plVar15 = *plVar15 + 1;
                                                    plVar16[3] = (longlong)plVar15;
                                                    lVar12 = FUN_23e94f9d0(param_1,local_e0,
                                                                           DAT_23ed6cd28);
                                                    if (lVar12 == 0) {
                                                      local_78 = *(undefined1 (*) [16])
                                                                  (param_1 + 0x60);
                                                      local_68 = *(longlong **)(param_1 + 0x70);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      *plVar14 = *plVar14 + -1;
                                                      if (*plVar14 == 0) {
                                                        FUN_23a334bc0(plVar14);
                                                      }
                                                      *plVar16 = *plVar16 + -1;
                                                      if (*plVar16 == 0) {
                                                        FUN_23a334bc0(plVar16);
                                                      }
                                                      uVar19 = 0x394;
                                                    }
                                                    else {
                                                      plVar16[4] = lVar12;
                                                      plVar15 = DAT_23eed92b8;
                                                      *DAT_23eed92b8 = *DAT_23eed92b8 + 1;
                                                      plVar16[5] = (longlong)plVar15;
                                                      plVar15 = (longlong *)
                                                                PyUnicode_Join(DAT_23ed6cd28,plVar16
                                                                              );
                                                      *plVar16 = *plVar16 + -1;
                                                      if (*plVar16 == 0) {
                                                        FUN_23a334bc0(plVar16);
                                                      }
                                                      if (plVar15 == (longlong *)0x0) {
                                                        local_78 = *(undefined1 (*) [16])
                                                                    (param_1 + 0x60);
                                                        local_68 = *(longlong **)(param_1 + 0x70);
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        uVar20 = 0x394;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        *plVar14 = *plVar14 + -1;
                                                        uVar19 = 0x394;
                                                        if (*plVar14 != 0) goto LAB_23e758dff;
                                                        goto LAB_23e75b08e;
                                                      }
                                                      *(undefined4 *)(plVar3 + 5) = 0x394;
                                                      plVar16 = (longlong *)
                                                                FUN_23e914090(param_1,plVar14);
                                                      *plVar14 = *plVar14 + -1;
                                                      if (*plVar14 == 0) {
                                                        FUN_23a334bc0(plVar14);
                                                      }
                                                      *plVar15 = *plVar15 + -1;
                                                      if (*plVar15 == 0) {
                                                        FUN_23a334bc0(plVar15);
                                                      }
                                                      if (plVar16 == (longlong *)0x0)
                                                      goto LAB_23e75b349;
                                                      *plVar16 = *plVar16 + -1;
                                                      if (*plVar16 == 0) {
                                                        FUN_23a334bc0(plVar16);
                                                      }
                                                      plVar14 = (longlong *)
                                                                FUN_23e8bc2f0(plVar2,DAT_23eed8a98);
                                                      if (plVar14 != (longlong *)0x0) {
                                                        plVar15 = (longlong *)
                                                                  FUN_23e8bc2f0(plVar14,
                                                  DAT_23eed92c0);
                                                  *plVar14 = *plVar14 + -1;
                                                  if (*plVar14 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  if (plVar15 != (longlong *)0x0) {
                                                    *local_c0 = *local_c0 + 1;
                                                    local_88 = plVar15;
                                                    plStack_80 = local_c0;
                                                    plVar14 = (longlong *)
                                                              FUN_23ab01810(param_1,&local_88);
                                                    if (plVar14 != (longlong *)0x0) {
LAB_23e75a40e:
                                                      *plVar14 = *plVar14 + -1;
                                                      if (*plVar14 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                      lVar10 = FUN_23e8e0ba0();
                                                      lVar12 = DAT_23eed8ce0;
                                                      if (lVar10 == 0) {
                                                        FUN_23e915740(param_1,local_78,DAT_23eed8c70
                                                                     );
                                                        uVar19 = 0x39a;
                                                      }
                                                      else {
                                                        *(undefined4 *)(plVar3 + 5) = 0x39a;
                                                        plVar14 = (longlong *)
                                                                  FUN_23e915840(param_1,lVar10,
                                                                                DAT_23eed8d40,
                                                                                *(undefined8 *)
                                                                                 (lVar12 + 0x18));
                                                        if (plVar14 != (longlong *)0x0) {
                                                          *plVar14 = *plVar14 + -1;
                                                          if (*plVar14 == 0) {
                                                            FUN_23a334bc0(plVar14);
                                                          }
                                                          goto LAB_23e758917;
                                                        }
                                                        local_78 = *(undefined1 (*) [16])
                                                                    (param_1 + 0x60);
                                                        local_68 = *(longlong **)(param_1 + 0x70);
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        uVar19 = 0x39a;
                                                      }
                                                      goto LAB_23e758dff;
                                                    }
                                                  }
                                                  }
                                                  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                                  local_68 = *(longlong **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  uVar19 = 0x395;
                                                  }
                                                  }
                                                  }
                                                  else {
                                                    iVar7 = FUN_23a35f020(pcVar21);
                                                    if (iVar7 == -1) goto LAB_23e75b2bb;
                                                    if (iVar7 != 0) {
                                                      iVar7 = PySequence_Contains(plVar8,plVar13);
                                                      if (iVar7 == -1) goto LAB_23e75b2bb;
                                                      if (iVar7 == 0) goto LAB_23e75a1db;
                                                    }
                                                    plVar14 = (longlong *)
                                                              FUN_23e8bc2f0(plVar2,DAT_23eed8b40);
                                                    plVar15 = DAT_23eed92b0;
                                                    if (plVar14 == (longlong *)0x0) {
LAB_23e75b41e:
                                                      local_78 = *(undefined1 (*) [16])
                                                                  (param_1 + 0x60);
                                                      local_68 = *(longlong **)(param_1 + 0x70);
                                                      uVar19 = 0x397;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                    }
                                                    else {
                                                      plVar16 = (longlong *)
                                                                FUN_23e916ad0(*(undefined8 *)
                                                                               (param_1 + 0x10),3);
                                                      *plVar15 = *plVar15 + 1;
                                                      plVar16[3] = (longlong)plVar15;
                                                      lVar12 = FUN_23e94f9d0(param_1,local_e0,
                                                                             DAT_23ed6cd28);
                                                      if (lVar12 == 0) {
                                                        local_78 = *(undefined1 (*) [16])
                                                                    (param_1 + 0x60);
                                                        local_68 = *(longlong **)(param_1 + 0x70);
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        *plVar14 = *plVar14 + -1;
                                                        if (*plVar14 == 0) {
                                                          FUN_23a334bc0(plVar14);
                                                        }
                                                        *plVar16 = *plVar16 + -1;
                                                        if (*plVar16 == 0) {
                                                          FUN_23a334bc0(plVar16);
                                                        }
                                                        uVar19 = 0x397;
                                                      }
                                                      else {
                                                        plVar16[4] = lVar12;
                                                        plVar15 = DAT_23eed92c8;
                                                        *DAT_23eed92c8 = *DAT_23eed92c8 + 1;
                                                        plVar16[5] = (longlong)plVar15;
                                                        plVar15 = (longlong *)
                                                                  PyUnicode_Join(DAT_23ed6cd28,
                                                                                 plVar16);
                                                        *plVar16 = *plVar16 + -1;
                                                        if (*plVar16 == 0) {
                                                          FUN_23a334bc0(plVar16);
                                                        }
                                                        if (plVar15 == (longlong *)0x0) {
                                                          local_78 = *(undefined1 (*) [16])
                                                                      (param_1 + 0x60);
                                                          local_68 = *(longlong **)(param_1 + 0x70);
                                                          uVar19 = 0x397;
                                                          uVar20 = 0x397;
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          *plVar14 = *plVar14 + -1;
                                                          lVar12 = *plVar14;
                                                          goto joined_r0x00023e75b088;
                                                        }
                                                        *(undefined4 *)(plVar3 + 5) = 0x397;
                                                        plVar16 = (longlong *)
                                                                  FUN_23e914090(param_1,plVar14);
                                                        *plVar14 = *plVar14 + -1;
                                                        if (*plVar14 == 0) {
                                                          FUN_23a334bc0(plVar14);
                                                        }
                                                        *plVar15 = *plVar15 + -1;
                                                        if (*plVar15 == 0) {
                                                          FUN_23a334bc0(plVar15);
                                                        }
                                                        if (plVar16 == (longlong *)0x0)
                                                        goto LAB_23e75b41e;
                                                        *plVar16 = *plVar16 + -1;
                                                        if (*plVar16 == 0) {
                                                          FUN_23a334bc0(plVar16);
                                                        }
                                                        plVar14 = (longlong *)
                                                                  FUN_23e8bc2f0(plVar2,DAT_23eed8a98
                                                                               );
                                                        if (plVar14 != (longlong *)0x0) {
                                                          plVar15 = (longlong *)
                                                                    FUN_23e8bc2f0(plVar14,
                                                  DAT_23eed92c0);
                                                  *plVar14 = *plVar14 + -1;
                                                  if (*plVar14 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  if (plVar15 != (longlong *)0x0) {
                                                    *local_d8 = *local_d8 + 1;
                                                    local_88 = plVar15;
                                                    plStack_80 = local_d8;
                                                    plVar14 = (longlong *)
                                                              FUN_23ab01810(param_1,&local_88);
                                                    if (plVar14 != (longlong *)0x0)
                                                    goto LAB_23e75a40e;
                                                  }
                                                  }
                                                  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                                  local_68 = *(longlong **)(param_1 + 0x70);
                                                  uVar19 = 0x398;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_23e758dff;
                                                  }
                                                  }
                                                  auVar5 = *(undefined1 (*) [16])(param_1 + 0x60);
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  plVar14 = *(longlong **)(param_1 + 0x70);
                                                  local_68 = (longlong *)0x0;
                                                  lVar12 = *local_b8;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  local_78 = (undefined1  [16])0x0;
                                                  *local_b8 = lVar12 + -1;
                                                  if (lVar12 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  uVar19 = 0x38d;
                                                  local_d0 = (longlong *)0x0;
                                                  local_b8 = (longlong *)0x0;
                                                  local_78 = auVar5;
                                                  local_68 = plVar14;
                                                }
                                              }
                                              goto LAB_23e758dff;
                                            }
                                          }
                                          local_68 = *(longlong **)(param_1 + 0x70);
                                          local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          lVar12 = *plVar15;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          *plVar15 = lVar12 + -1;
                                          if (lVar12 + -1 == 0) {
                                            FUN_23a334bc0(plVar15);
                                          }
                                          *plVar16 = *plVar16 + -1;
                                          if (*plVar16 == 0) {
                                            FUN_23a334bc0(plVar16);
                                          }
                                          uVar19 = 0x38a;
                                          local_d0 = (longlong *)0x0;
                                          local_b8 = (longlong *)0x0;
                                          goto LAB_23e758dff;
                                        }
                                      }
                                    }
                                    plVar15 = local_68;
                                    uVar22 = local_78._0_8_;
                                    uVar23 = local_78._8_8_;
                                    local_68 = (longlong *)0x0;
                                    local_78 = (undefined1  [16])0x0;
                                    *plVar14 = *plVar14 + -1;
                                    if (*plVar14 == 0) {
                                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                                    }
                                    local_68 = (longlong *)0x0;
                                    local_78 = (undefined1  [16])0x0;
                                    if ((plVar13 != (longlong *)0x0) &&
                                       (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
                                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                                    }
                                    if ((local_e0 != (longlong *)0x0) &&
                                       (lVar12 = *local_e0, *local_e0 = lVar12 + -1,
                                       lVar12 + -1 == 0)) {
                                      (**(code **)(local_e0[1] + 0x30))();
                                    }
                                    if ((local_c8 != (longlong *)0x0) &&
                                       (lVar12 = *local_c8, *local_c8 = lVar12 + -1,
                                       lVar12 + -1 == 0)) {
                                      (**(code **)(local_c8[1] + 0x30))();
                                    }
                                  }
                                  uVar19 = 0x389;
                                  local_78._8_8_ = uVar23;
                                  local_78._0_8_ = uVar22;
                                  local_68 = plVar15;
                                  goto LAB_23e75a63c;
                                }
                                local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                local_68 = *(longlong **)(param_1 + 0x70);
                                local_d0 = (longlong *)0x0;
                                plVar13 = (longlong *)0x0;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                uVar19 = 0x388;
                                local_b8 = (longlong *)0x0;
                                local_c8 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                local_e0 = (longlong *)0x0;
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
          }
        }
      }
    }
LAB_23e758dff:
    if (local_68 == (longlong *)0x0) {
LAB_23e758c00:
      plVar14 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar15 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar15;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar18 = _PyRuntime_exref;
      plVar14[2] = 0;
      plVar14[3] = (longlong)plVar3;
      *plVar3 = *plVar3 + 1;
      lVar12 = *(longlong *)(pcVar18 + 0x1f8);
      *(undefined4 *)((longlong)plVar14 + 0x24) = uVar19;
      lVar12 = *(longlong *)(lVar12 + 0x10);
      *(undefined4 *)(plVar14 + 4) = 0xffffffff;
      lVar12 = *(longlong *)(lVar12 + 0x2e8);
      lVar10 = plVar14[-1];
      puVar4 = *(undefined8 **)(lVar12 + 8);
      *puVar4 = plVar14 + -2;
      plVar14[-2] = lVar12;
      plVar14[-1] = (ulonglong)((uint)lVar10 & 3) | (ulonglong)puVar4;
      *(longlong **)(lVar12 + 8) = plVar14 + -2;
      if ((local_68 != (longlong *)0x0) && (*local_68 = *local_68 + -1, *local_68 == 0)) {
        (**(code **)(local_68[1] + 0x30))(local_68);
      }
      goto LAB_23e758ecb;
    }
  }
  else {
    if (plVar9 != (longlong *)0x0) goto LAB_23e7583ea;
LAB_23e758b73:
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    plVar13 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar21 = (code *)0x0;
    plVar8 = (longlong *)0x0;
    uVar19 = 0x378;
    local_d0 = (longlong *)0x0;
    local_b8 = (longlong *)0x0;
    local_c8 = (longlong *)0x0;
    local_e0 = (longlong *)0x0;
    local_c0 = (longlong *)0x0;
    local_d8 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (local_68 == (longlong *)0x0) {
      local_68 = (longlong *)0x0;
      goto LAB_23e758c00;
    }
  }
  plVar14 = local_68;
  plVar15 = DAT_23ed6a4f8;
  if ((longlong *)local_68[3] != plVar3) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar16 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar16;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar18 = _PyRuntime_exref;
    plVar15[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar12 = *(longlong *)(pcVar18 + 0x1f8);
    *(undefined4 *)((longlong)plVar15 + 0x24) = uVar19;
    *(undefined4 *)(plVar15 + 4) = 0xffffffff;
    lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
    lVar10 = plVar15[-1];
    puVar4 = *(undefined8 **)(lVar12 + 8);
    *puVar4 = plVar15 + -2;
    plVar15[-2] = lVar12;
    plVar15[-1] = (ulonglong)((uint)lVar10 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar12 + 8) = plVar15 + -2;
    plVar15[2] = (longlong)plVar14;
    *plVar14 = *plVar14 + 1;
    plVar14 = plVar15;
    if ((local_68 != (longlong *)0x0) && (*local_68 = *local_68 + -1, *local_68 == 0)) {
      (**(code **)(local_68[1] + 0x30))(local_68);
    }
  }
LAB_23e758ecb:
  local_68 = plVar14;
  FUN_23e8bba40(plVar3,"oooooooooooo",plVar2,plVar8,plVar9,pcVar21,local_d8,local_c0,plVar11,plVar13
                ,local_e0,local_c8,local_b8,local_d0);
  if (DAT_23eedade8 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    DAT_23eedade8 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar12 + 0x28);
  plVar14 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar14 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      (**(code **)(plVar14[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  plVar14 = local_68;
  plVar3[0xf] = 0;
  uVar22 = local_78._0_8_;
  uVar23 = local_78._8_8_;
  local_78 = (undefined1  [16])0x0;
  local_68 = (longlong *)0x0;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((pcVar21 != (code *)0x0) &&
     (*(longlong *)pcVar21 = *(longlong *)pcVar21 + -1, *(longlong *)pcVar21 == 0)) {
    (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))(pcVar21);
  }
  if ((local_d8 != (longlong *)0x0) &&
     (lVar12 = *local_d8, *local_d8 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_d8[1] + 0x30))(local_d8);
  }
  if ((local_c0 != (longlong *)0x0) &&
     (lVar12 = *local_c0, *local_c0 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_c0[1] + 0x30))(local_c0);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((local_e0 != (longlong *)0x0) &&
     (lVar12 = *local_e0, *local_e0 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_e0[1] + 0x30))(local_e0);
  }
  if ((local_c8 != (longlong *)0x0) &&
     (lVar12 = *local_c8, *local_c8 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_c8[1] + 0x30))(local_c8);
  }
  if ((local_b8 != (longlong *)0x0) &&
     (lVar12 = *local_b8, *local_b8 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_b8[1] + 0x30))(local_b8);
  }
  if ((local_d0 != (longlong *)0x0) &&
     (lVar12 = *local_d0, *local_d0 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(local_d0[1] + 0x30))(local_d0);
  }
  *plVar2 = *plVar2 + -1;
  local_68 = plVar14;
  local_78._0_8_ = uVar22;
  local_78._8_8_ = uVar23;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,local_78._0_8_,local_78._8_8_,local_68);
  return (code *)0x0;
}
