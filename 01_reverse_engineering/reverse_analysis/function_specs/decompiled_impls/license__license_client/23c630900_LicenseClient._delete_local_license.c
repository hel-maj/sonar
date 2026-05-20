/* ===== 23c630900 license.license_client:262 ===== */
/* ghidra_name=FUN_23c630900 entry=23c630900 size=18214 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

longlong * FUN_23c630900(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  char cVar4;
  int iVar5;
  longlong *plVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong lVar15;
  code *pcVar16;
  code *pcVar17;
  code *pcVar18;
  undefined8 uVar19;
  undefined8 *puVar20;
  code *in_R11;
  undefined4 uVar21;
  longlong *local_108;
  longlong *local_100;
  code *local_f8;
  code *local_f0;
  code *local_e8;
  code **local_e0;
  longlong *local_d8;
  code *local_a8;
  code *pcStack_a0;
  undefined1 local_98 [16];
  code *local_88 [2];
  longlong *local_78;
  code *pcStack_70;
  code *local_68;
  
  plVar6 = _DAT_23ee29c80;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23ee29c80 == (longlong *)0x0) {
LAB_23c630945:
    _DAT_23ee29c80 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23ee29c78,DAT_23ee29d18,0x48);
  }
  else {
    lVar7 = *_DAT_23ee29c80;
    if (1 < lVar7) {
      *_DAT_23ee29c80 = lVar7 + -1;
      goto LAB_23c630945;
    }
    if (_DAT_23ee29c80[2] != 0) {
      *_DAT_23ee29c80 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      goto LAB_23c630945;
    }
  }
  plVar2 = _DAT_23ee29c80;
  lVar7 = *(longlong *)(param_1 + 0x38);
  plVar6 = _DAT_23ee29c80 + 9;
  lVar15 = *(longlong *)(lVar7 + 8);
  _DAT_23ee29c80[0xf] = lVar15;
  *(longlong **)(lVar7 + 8) = plVar6;
  if ((lVar15 != 0) &&
     (((*(char *)(lVar15 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar15 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar15 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar15 + 0x38))) && (plVar2[0xe] != 0)))) {
    plVar6 = *(longlong **)(lVar15 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar6;
    if (plVar6 != (longlong *)0x0) {
      *plVar6 = *plVar6 + 1;
    }
  }
  *plVar2 = *plVar2 + 1;
  uVar19 = DAT_23ee28390;
  *(undefined4 *)(plVar2 + 8) = 0;
  plVar6 = (longlong *)FUN_23e8bc2f0(plVar1,uVar19);
  if (plVar6 == (longlong *)0x0) {
    local_f0 = *(code **)(param_1 + 0x60);
    pcVar18 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    local_e8 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar6 = (longlong *)0x0;
    if (pcVar18 != (code *)0x0) {
      if (*(longlong **)(pcVar18 + 0x18) == plVar2) {
        plVar10 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        local_100 = (longlong *)0x0;
        local_108 = (longlong *)0x0;
        pcVar17 = pcVar18;
        goto LAB_23c631de0;
      }
      goto LAB_23c631d1e;
    }
LAB_23c6327ba:
    plVar6 = (longlong *)0x0;
    local_100 = (longlong *)0x0;
    local_108 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    local_f8 = _PyRuntime_exref;
    iVar5 = 0x10d;
    local_e0 = &DAT_23ed6a4f8;
  }
  else {
    iVar5 = FUN_23a35f020(plVar6);
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    plVar12 = _DAT_23ee28780;
    if (iVar5 == -1) {
      local_f0 = *(code **)(param_1 + 0x60);
      pcVar18 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_e8 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (pcVar18 == (code *)0x0) goto LAB_23c6327ba;
      if (*(longlong **)(pcVar18 + 0x18) == plVar2) {
        plVar10 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        local_100 = (longlong *)0x0;
        plVar6 = (longlong *)0x0;
        local_108 = (longlong *)0x0;
        pcVar17 = pcVar18;
        goto LAB_23c631de0;
      }
LAB_23c631d1e:
      plVar6 = (longlong *)0x0;
      local_100 = (longlong *)0x0;
      local_108 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      iVar5 = 0x10d;
      local_f8 = _PyRuntime_exref;
      local_e0 = &DAT_23ed6a4f8;
LAB_23c631d3f:
      pcVar17 = *local_e0;
      if (pcVar17 == (code *)0x0) {
        pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        *local_e0 = *(code **)pcVar17;
        *(longlong *)pcVar17 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong **)(pcVar17 + 0x18) = plVar2;
      *plVar2 = *plVar2 + 1;
      lVar7 = *(longlong *)(local_f8 + 0x1f8);
      *(int *)(pcVar17 + 0x24) = iVar5;
      *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
      lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0x10) + 0x2e8);
      lVar15 = *(longlong *)(pcVar17 + -8);
      puVar20 = *(undefined8 **)(lVar7 + 8);
      *puVar20 = pcVar17 + -0x10;
      *(longlong *)(pcVar17 + -0x10) = lVar7;
      *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar20;
      lVar15 = *(longlong *)pcVar18;
      *(code **)(lVar7 + 8) = pcVar17 + -0x10;
      *(code **)(pcVar17 + 0x10) = pcVar18;
      if (lVar15 == 0) {
        (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))(pcVar18);
      }
      goto LAB_23c631de0;
    }
    if (iVar5 == 0) {
      plVar10 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      local_100 = (longlong *)0x0;
      plVar6 = (longlong *)0x0;
      *_DAT_23ee28780 = *_DAT_23ee28780 + 1;
      local_108 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      goto LAB_23c630a30;
    }
    lVar7 = FUN_23ead5f40();
    if (lVar7 != 0) {
      plVar8 = (longlong *)FUN_23e8bc2f0(lVar7,DAT_23ee28400);
      plVar6 = _DAT_23ee28788;
      if (plVar8 == (longlong *)0x0) {
        local_f0 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar14 = *(longlong **)(param_1 + 0x60);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar6 = plVar8;
        pcVar18 = *(code **)(param_1 + 0x68);
        goto LAB_23c631539;
      }
      lVar7 = *(longlong *)(param_1 + 0x10);
      plVar11 = *(longlong **)(lVar7 + 0xe28);
      if (plVar11 == (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
      }
      else {
        lVar15 = plVar11[3];
        *(int *)(lVar7 + 0xec0) = *(int *)(lVar7 + 0xec0) + -1;
        *(longlong *)(lVar7 + 0xe28) = lVar15;
        *plVar11 = 1;
      }
      local_f8 = _PyRuntime_exref;
      *(undefined1 (*) [16])(plVar11 + 4) = (undefined1  [16])0x0;
      lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(local_f8 + 0x1f8) + 0x10) + 0x2e8);
      lVar15 = plVar11[-1];
      puVar20 = *(undefined8 **)(lVar7 + 8);
      *puVar20 = plVar11 + -2;
      plVar11[-2] = lVar7;
      plVar11[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar20;
      *(longlong **)(lVar7 + 8) = plVar11 + -2;
      uVar19 = DAT_23ee28390;
      *plVar6 = *plVar6 + 1;
      plVar11[3] = (longlong)plVar6;
      plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,uVar19);
      if (plVar9 == (longlong *)0x0) {
LAB_23c631c48:
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar18 = *(code **)(param_1 + 0x68);
        local_f0 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          uVar21 = 0x111;
          (**(code **)(plVar11[1] + 0x30))(plVar11);
LAB_23c631c9c:
          plVar10 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          local_100 = (longlong *)0x0;
          plVar6 = (longlong *)0x0;
          local_108 = (longlong *)0x0;
        }
        else {
          uVar21 = 0x111;
LAB_23c6320e6:
          plVar10 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          plVar6 = (longlong *)0x0;
          local_100 = (longlong *)0x0;
          local_108 = (longlong *)0x0;
        }
        goto LAB_23c631565;
      }
      uVar19 = _DAT_23ee28660;
      plVar10 = (longlong *)FUN_23a38cc10(param_1,plVar9);
      iVar5 = (int)uVar19;
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      pcVar18 = DAT_23ed6cd28;
      if (plVar10 == (longlong *)0x0) goto LAB_23c631c48;
      if (DAT_23ed6a4c0 != (longlong *)0x0) {
LAB_23c630cdd:
        pcStack_70 = pcVar18;
        local_78 = plVar10;
        lVar7 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_78);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        plVar6 = _DAT_23ee28668;
        if (lVar7 == 0) goto LAB_23c631c48;
        plVar11[4] = lVar7;
        *plVar6 = *plVar6 + 1;
        plVar11[5] = (longlong)plVar6;
        plVar9 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar11);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if (plVar9 != (longlong *)0x0) {
          *(undefined4 *)(plVar2 + 5) = 0x111;
          plVar6 = plVar9;
          plVar11 = (longlong *)FUN_23e914090(param_1,plVar8);
          iVar5 = (int)plVar6;
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          if (plVar11 == (longlong *)0x0) {
            plVar14 = *(longlong **)(param_1 + 0x60);
            pcVar18 = *(code **)(param_1 + 0x68);
            local_f0 = *(code **)(param_1 + 0x70);
            plVar10 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar9 = (longlong *)0x0;
            plVar6 = (longlong *)0x0;
            uVar21 = 0x111;
            *(undefined8 *)(param_1 + 0x70) = 0;
            local_100 = (longlong *)0x0;
            local_108 = (longlong *)0x0;
            goto LAB_23c631565;
          }
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          plVar6 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23ee28670);
          if (plVar6 == (longlong *)0x0) {
LAB_23c632aab:
            plVar14 = *(longlong **)(param_1 + 0x60);
            pcVar18 = *(code **)(param_1 + 0x68);
            local_f0 = *(code **)(param_1 + 0x70);
            plVar10 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar11 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            uVar21 = 0x113;
            *(undefined8 *)(param_1 + 0x70) = 0;
            local_100 = (longlong *)0x0;
            local_108 = (longlong *)0x0;
            goto LAB_23c631565;
          }
          pcVar18 = DAT_23ed6cd28;
          plVar8 = plVar6;
          if (DAT_23ed6a4c0 == (longlong *)0x0) {
            plVar12 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            if (plVar12 == (longlong *)0x0) goto LAB_23c63337f;
            *plVar12 = *plVar12 + 1;
            DAT_23ed6a4c0 = plVar12;
          }
          local_78 = plVar6;
          pcStack_70 = pcVar18;
          lVar7 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_78);
          *plVar6 = *plVar6 + -1;
          if (*plVar6 == 0) {
            (**(code **)(plVar6[1] + 0x30))(plVar6);
          }
          if (lVar7 == 0) {
            plVar14 = *(longlong **)(param_1 + 0x60);
            pcVar18 = *(code **)(param_1 + 0x68);
            local_f0 = *(code **)(param_1 + 0x70);
            plVar10 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar11 = (longlong *)0x0;
            plVar6 = (longlong *)0x0;
            uVar21 = 0x113;
            *(undefined8 *)(param_1 + 0x70) = 0;
            local_100 = (longlong *)0x0;
            local_108 = (longlong *)0x0;
            plVar9 = (longlong *)0x0;
            goto LAB_23c631565;
          }
          lVar15 = *(longlong *)(param_1 + 0x10);
          plVar11 = *(longlong **)(lVar15 + 0xe30);
          if (plVar11 == (longlong *)0x0) {
            plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,4);
          }
          else {
            lVar3 = plVar11[3];
            *(int *)(lVar15 + 0xec4) = *(int *)(lVar15 + 0xec4) + -1;
            *(longlong *)(lVar15 + 0xe30) = lVar3;
            *plVar11 = 1;
          }
          plVar11[6] = 0;
          *(undefined1 (*) [16])(plVar11 + 4) = (undefined1  [16])0x0;
          lVar15 = *(longlong *)(*(longlong *)(*(longlong *)(local_f8 + 0x1f8) + 0x10) + 0x2e8);
          lVar3 = plVar11[-1];
          puVar20 = *(undefined8 **)(lVar15 + 8);
          *puVar20 = plVar11 + -2;
          plVar11[-2] = lVar15;
          plVar11[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar20;
          *(longlong **)(lVar15 + 8) = plVar11 + -2;
          uVar19 = _DAT_23ee28678;
          plVar11[3] = lVar7;
          plVar6 = DAT_23ed6cea0;
          *DAT_23ed6cea0 = *DAT_23ed6cea0 + 1;
          plVar11[4] = (longlong)plVar6;
          plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,uVar19);
          iVar5 = (int)puVar20;
          if (plVar9 != (longlong *)0x0) {
            pcVar18 = DAT_23ed6cd28;
            if (DAT_23ed6a4c0 == (longlong *)0x0) {
              plVar6 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              if (plVar6 == (longlong *)0x0) goto LAB_23c63337f;
              *plVar6 = *plVar6 + 1;
              DAT_23ed6a4c0 = plVar6;
            }
            local_78 = plVar9;
            pcStack_70 = pcVar18;
            lVar7 = FUN_23e94ed00(param_1);
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            plVar6 = _DAT_23ee28790;
            if (lVar7 != 0) {
              plVar11[5] = lVar7;
              *plVar6 = *plVar6 + 1;
              plVar11[6] = (longlong)plVar6;
              plVar6 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar11);
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              uVar19 = DAT_23ee28688;
              if (plVar6 == (longlong *)0x0) goto LAB_23c632aab;
              plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ee28390);
              if (plVar11 == (longlong *)0x0) {
                plVar14 = *(longlong **)(param_1 + 0x60);
                pcVar18 = *(code **)(param_1 + 0x68);
                local_f0 = *(code **)(param_1 + 0x70);
                local_100 = (longlong *)0x0;
                plVar10 = (longlong *)0x0;
                plVar9 = (longlong *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar21 = 0x115;
                local_108 = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar11 = (longlong *)0x0;
              }
              else {
                plVar8 = (longlong *)_PyDict_NewPresized(2);
                PyDict_SetItem(plVar8,uVar19,plVar11);
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  FUN_23a334bc0(plVar11);
                }
                uVar19 = DAT_23ee28450;
                plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ee283a0);
                if (plVar11 == (longlong *)0x0) {
                  plVar14 = *(longlong **)(param_1 + 0x60);
                  pcVar18 = *(code **)(param_1 + 0x68);
                  local_f0 = *(code **)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *plVar8 = *plVar8 + -1;
                  plVar11 = (longlong *)0x0;
                  if (*plVar8 == 0) {
                    plVar10 = (longlong *)0x0;
                    plVar9 = (longlong *)0x0;
                    FUN_23a334bc0(plVar8);
                    uVar21 = 0x116;
                    local_100 = (longlong *)0x0;
                    local_108 = (longlong *)0x0;
                  }
                  else {
                    plVar10 = (longlong *)0x0;
                    plVar9 = (longlong *)0x0;
                    uVar21 = 0x116;
                    local_100 = (longlong *)0x0;
                    local_108 = (longlong *)0x0;
                  }
                }
                else {
                  PyDict_SetItem(plVar8,uVar19,plVar11);
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    FUN_23a334bc0(plVar11);
                  }
                  lVar7 = FUN_23ead5a00();
                  plVar9 = plVar8;
                  if (lVar7 == 0) {
                    plVar10 = (longlong *)0x0;
                    uVar21 = 0x119;
                    FUN_23e915740(param_1,&local_78,_DAT_23ee28690);
                    local_100 = (longlong *)0x0;
                    local_108 = (longlong *)0x0;
                    plVar11 = (longlong *)0x0;
                    local_f0 = local_68;
                    plVar14 = local_78;
                    pcVar18 = pcStack_70;
                  }
                  else {
                    plVar10 = (longlong *)FUN_23e8bc2f0(lVar7,_DAT_23ee28698);
                    uVar19 = _DAT_23ee286a8;
                    pcVar18 = _DAT_23ee286a0;
                    if (plVar10 == (longlong *)0x0) {
                      local_f0 = *(code **)(param_1 + 0x70);
                      plVar14 = *(longlong **)(param_1 + 0x60);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      plVar10 = (longlong *)0x0;
                      plVar11 = (longlong *)0x0;
                      local_100 = (longlong *)0x0;
                      uVar21 = 0x119;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      local_108 = (longlong *)0x0;
                      pcVar18 = *(code **)(param_1 + 0x68);
                    }
                    else {
                      *(undefined4 *)(plVar2 + 5) = 0x119;
                      local_98._0_8_ = plVar6;
                      pcStack_70 = pcVar18;
                      local_78 = plVar8;
                      plVar11 = (longlong *)FUN_23e939900(param_1,plVar10,local_98,&local_78,uVar19)
                      ;
                      lVar7 = *plVar10;
                      *plVar10 = lVar7 + -1;
                      if (lVar7 + -1 == 0) {
                        FUN_23a334bc0(plVar10);
                      }
                      if (plVar11 == (longlong *)0x0) {
                        plVar14 = *(longlong **)(param_1 + 0x60);
                        local_100 = (longlong *)0x0;
                        local_f0 = *(code **)(param_1 + 0x70);
                        local_108 = (longlong *)0x0;
                        uVar21 = 0x119;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        plVar10 = (longlong *)0x0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        pcVar18 = *(code **)(param_1 + 0x68);
                      }
                      else {
                        plVar10 = (longlong *)FUN_23e8bc2f0(plVar11,_DAT_23ee286b0);
                        if (plVar10 == (longlong *)0x0) {
                          plVar14 = *(longlong **)(param_1 + 0x60);
                          local_f0 = *(code **)(param_1 + 0x70);
                          local_100 = (longlong *)0x0;
                          plVar10 = (longlong *)0x0;
                          uVar21 = 0x11b;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          local_108 = (longlong *)0x0;
                          pcVar18 = *(code **)(param_1 + 0x68);
                        }
                        else {
                          iVar5 = FUN_23e97a530(plVar10,_DAT_23ee286b8);
                          lVar7 = *plVar10;
                          *plVar10 = lVar7 + -1;
                          if (lVar7 + -1 == 0) {
                            FUN_23a334bc0(plVar10);
                          }
                          if (iVar5 == -1) {
                            plVar14 = *(longlong **)(param_1 + 0x60);
                            local_f0 = *(code **)(param_1 + 0x70);
                            local_100 = (longlong *)0x0;
                            plVar10 = (longlong *)0x0;
                            uVar21 = 0x11b;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            local_108 = (longlong *)0x0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            pcVar18 = *(code **)(param_1 + 0x68);
                          }
                          else if (iVar5 == 1) {
                            *(undefined4 *)(plVar2 + 5) = 0x11c;
                            local_108 = (longlong *)FUN_23e91bfe0(param_1,plVar11,_DAT_23ee28488);
                            uVar19 = DAT_23ee28688;
                            if (local_108 == (longlong *)0x0) {
                              plVar14 = *(longlong **)(param_1 + 0x60);
                              local_f0 = *(code **)(param_1 + 0x70);
                              local_100 = (longlong *)0x0;
                              plVar10 = (longlong *)0x0;
                              uVar21 = 0x11c;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              pcVar18 = *(code **)(param_1 + 0x68);
                            }
                            else {
                              plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ee28390);
                              if (plVar10 == (longlong *)0x0) {
                                plVar14 = *(longlong **)(param_1 + 0x60);
                                local_f0 = *(code **)(param_1 + 0x70);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plVar10 = (longlong *)0x0;
                                uVar21 = 0x120;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                local_100 = (longlong *)0x0;
                                pcVar18 = *(code **)(param_1 + 0x68);
                              }
                              else {
                                plVar12 = (longlong *)_PyDict_NewPresized(4);
                                PyDict_SetItem(plVar12,uVar19,plVar10);
                                lVar7 = *plVar10;
                                *plVar10 = lVar7 + -1;
                                if (lVar7 + -1 == 0) {
                                  FUN_23a334bc0(plVar10);
                                }
                                uVar19 = DAT_23ee28450;
                                plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ee283a0);
                                if (plVar10 == (longlong *)0x0) {
                                  plVar14 = *(longlong **)(param_1 + 0x60);
                                  pcVar18 = *(code **)(param_1 + 0x68);
                                  local_f0 = *(code **)(param_1 + 0x70);
                                  uVar21 = 0x121;
LAB_23c633be7:
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  *plVar12 = *plVar12 + -1;
                                  if (*plVar12 == 0) {
                                    plVar10 = (longlong *)0x0;
                                    FUN_23a334bc0(plVar12);
                                    local_100 = (longlong *)0x0;
                                    goto LAB_23c631565;
                                  }
                                }
                                else {
                                  PyDict_SetItem(plVar12,uVar19,plVar10);
                                  *plVar10 = *plVar10 + -1;
                                  if (*plVar10 == 0) {
                                    FUN_23a334bc0(plVar10);
                                  }
                                  uVar19 = DAT_23ee286c0;
                                  plVar10 = (longlong *)FUN_23e8bc2f0(local_108,DAT_23ed6ce40);
                                  if (plVar10 == (longlong *)0x0) {
LAB_23c633c83:
                                    plVar14 = *(longlong **)(param_1 + 0x60);
                                    pcVar18 = *(code **)(param_1 + 0x68);
                                    local_f0 = *(code **)(param_1 + 0x70);
                                    uVar21 = 0x122;
                                    goto LAB_23c633be7;
                                  }
                                  *(undefined4 *)(plVar2 + 5) = 0x122;
                                  plVar14 = (longlong *)FUN_23e94bb80(param_1,plVar10,DAT_23ee28578)
                                  ;
                                  *plVar10 = *plVar10 + -1;
                                  if (*plVar10 == 0) {
                                    FUN_23a334bc0(plVar10);
                                  }
                                  if (plVar14 == (longlong *)0x0) goto LAB_23c633c83;
                                  PyDict_SetItem(plVar12,uVar19);
                                  *plVar14 = *plVar14 + -1;
                                  if (*plVar14 == 0) {
                                    FUN_23a334bc0(plVar14);
                                  }
                                  uVar19 = DAT_23ee286c8;
                                  plVar10 = (longlong *)FUN_23e8bc2f0(local_108,DAT_23ed6ce40);
                                  if (plVar10 == (longlong *)0x0) {
LAB_23c633bd8:
                                    plVar14 = *(longlong **)(param_1 + 0x60);
                                    pcVar18 = *(code **)(param_1 + 0x68);
                                    local_f0 = *(code **)(param_1 + 0x70);
                                    uVar21 = 0x123;
                                    goto LAB_23c633be7;
                                  }
                                  *(undefined4 *)(plVar2 + 5) = 0x123;
                                  plVar14 = (longlong *)FUN_23e94bb80(param_1,plVar10,DAT_23ee286d0)
                                  ;
                                  *plVar10 = *plVar10 + -1;
                                  if (*plVar10 == 0) {
                                    FUN_23a334bc0(plVar10);
                                  }
                                  if (plVar14 == (longlong *)0x0) goto LAB_23c633bd8;
                                  PyDict_SetItem(plVar12,uVar19);
                                  *plVar14 = *plVar14 + -1;
                                  if (*plVar14 == 0) {
                                    FUN_23a334bc0(plVar14);
                                  }
                                  cVar4 = FUN_23e8d9ac0(plVar1,DAT_23ee283a8,plVar12);
                                  *plVar12 = *plVar12 + -1;
                                  if (*plVar12 == 0) {
                                    FUN_23a334bc0(plVar12);
                                  }
                                  if (cVar4 == '\0') {
                                    plVar14 = *(longlong **)(param_1 + 0x60);
                                    local_f0 = *(code **)(param_1 + 0x70);
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    uVar21 = 0x11f;
                                    plVar10 = (longlong *)0x0;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    local_100 = (longlong *)0x0;
                                    pcVar18 = *(code **)(param_1 + 0x68);
                                    goto LAB_23c631565;
                                  }
                                  cVar4 = FUN_23e8d9ac0(plVar1,DAT_23ee283b0);
                                  if (cVar4 == '\0') {
                                    plVar14 = *(longlong **)(param_1 + 0x60);
                                    local_f0 = *(code **)(param_1 + 0x70);
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    uVar21 = 0x125;
                                    plVar10 = (longlong *)0x0;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    local_100 = (longlong *)0x0;
                                    pcVar18 = *(code **)(param_1 + 0x68);
                                    goto LAB_23c631565;
                                  }
                                  plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23ee286d8);
                                  if (plVar12 == (longlong *)0x0) {
                                    plVar14 = *(longlong **)(param_1 + 0x60);
                                    local_f0 = *(code **)(param_1 + 0x70);
                                    local_100 = (longlong *)0x0;
                                    uVar21 = 0x128;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    plVar10 = (longlong *)0x0;
                                    pcVar18 = *(code **)(param_1 + 0x68);
                                    goto LAB_23c631565;
                                  }
                                  plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ee283a8);
                                  if (plVar10 == (longlong *)0x0) {
                                    plVar14 = *(longlong **)(param_1 + 0x60);
                                    pcVar18 = *(code **)(param_1 + 0x68);
                                    local_f0 = *(code **)(param_1 + 0x70);
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    *plVar12 = *plVar12 + -1;
                                    local_100 = (longlong *)0x0;
                                    if (*plVar12 == 0) {
                                      plVar10 = (longlong *)0x0;
                                      uVar21 = 0x128;
                                      FUN_23a334bc0(plVar12);
                                    }
                                    else {
                                      plVar10 = (longlong *)0x0;
                                      uVar21 = 0x128;
                                    }
                                    goto LAB_23c631565;
                                  }
                                  *(undefined4 *)(plVar2 + 5) = 0x128;
                                  plVar14 = (longlong *)FUN_23e914090(param_1,plVar12,plVar10);
                                  *plVar12 = *plVar12 + -1;
                                  if (*plVar12 == 0) {
                                    FUN_23a334bc0(plVar12);
                                  }
                                  lVar7 = *plVar10;
                                  *plVar10 = lVar7 + -1;
                                  if (lVar7 + -1 == 0) {
                                    FUN_23a334bc0();
                                  }
                                  if (plVar14 == (longlong *)0x0) {
                                    local_f0 = *(code **)(param_1 + 0x70);
                                    plVar14 = *(longlong **)(param_1 + 0x60);
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    plVar10 = (longlong *)0x0;
                                    uVar21 = 0x128;
                                    local_100 = (longlong *)0x0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    pcVar18 = *(code **)(param_1 + 0x68);
                                    goto LAB_23c631565;
                                  }
                                  *plVar14 = *plVar14 + -1;
                                  if (*plVar14 == 0) {
                                    FUN_23a334bc0(plVar14);
                                  }
                                  lVar7 = FUN_23ead5f40();
                                  if (lVar7 == 0) {
                                    plVar10 = (longlong *)0x0;
                                    uVar21 = 0x12a;
                                    FUN_23e915740(param_1,&local_78,DAT_23ee283f8);
                                    local_100 = (longlong *)0x0;
                                    local_f0 = local_68;
                                    plVar14 = local_78;
                                    pcVar18 = pcStack_70;
                                    goto LAB_23c631565;
                                  }
                                  plVar12 = (longlong *)FUN_23e8bc2f0(lVar7,DAT_23ee28400);
                                  plVar10 = _DAT_23ee28798;
                                  if (plVar12 == (longlong *)0x0) {
                                    plVar14 = *(longlong **)(param_1 + 0x60);
                                    local_f0 = *(code **)(param_1 + 0x70);
                                    local_100 = (longlong *)0x0;
                                    uVar21 = 0x12a;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    plVar10 = (longlong *)0x0;
                                    pcVar18 = *(code **)(param_1 + 0x68);
                                    goto LAB_23c631565;
                                  }
                                  plVar13 = (longlong *)
                                            FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
                                  *plVar10 = *plVar10 + 1;
                                  plVar13[3] = (longlong)plVar10;
                                  plVar10 = (longlong *)FUN_23e8bc2f0(local_108,DAT_23ed6ce40);
                                  uVar19 = DAT_23ee28578;
                                  if (plVar10 != (longlong *)0x0) {
                                    *(undefined4 *)(plVar2 + 5) = 0x12a;
                                    plVar14 = (longlong *)FUN_23e94bb80(param_1,plVar10,uVar19);
                                    *plVar10 = *plVar10 + -1;
                                    if (*plVar10 == 0) {
                                      FUN_23a334bc0(plVar10);
                                    }
                                    if (plVar14 != (longlong *)0x0) {
                                      lVar7 = FUN_23e94f9d0(param_1,plVar14,DAT_23ed6cd28);
                                      *plVar14 = *plVar14 + -1;
                                      if (*plVar14 == 0) {
                                        FUN_23a334bc0(plVar14);
                                      }
                                      if (lVar7 != 0) {
                                        plVar13[4] = lVar7;
                                        plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar13);
                                        *plVar13 = *plVar13 + -1;
                                        if (*plVar13 == 0) {
                                          FUN_23a334bc0(plVar13);
                                        }
                                        if (plVar10 == (longlong *)0x0) {
                                          plVar14 = *(longlong **)(param_1 + 0x60);
                                          pcVar18 = *(code **)(param_1 + 0x68);
                                          local_f0 = *(code **)(param_1 + 0x70);
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *plVar12 = *plVar12 + -1;
                                          local_100 = (longlong *)0x0;
                                          if (*plVar12 == 0) {
                                            plVar10 = (longlong *)0x0;
                                            uVar21 = 0x12a;
                                            FUN_23a334bc0(plVar12);
                                          }
                                          else {
                                            plVar10 = (longlong *)0x0;
                                            uVar21 = 0x12a;
                                          }
                                        }
                                        else {
                                          *(undefined4 *)(plVar2 + 5) = 0x12a;
                                          plVar14 = (longlong *)
                                                    FUN_23e914090(param_1,plVar12,plVar10);
                                          *plVar12 = *plVar12 + -1;
                                          if (*plVar12 == 0) {
                                            FUN_23a334bc0(plVar12);
                                          }
                                          lVar7 = *plVar10;
                                          *plVar10 = lVar7 + -1;
                                          if (lVar7 + -1 == 0) {
                                            FUN_23a334bc0(plVar10);
                                          }
                                          if (plVar14 != (longlong *)0x0) {
                                            *plVar14 = *plVar14 + -1;
                                            if (*plVar14 == 0) {
                                              FUN_23a334bc0(plVar14);
                                            }
                                            plVar12 = _DAT_23ee287a0;
                                            plVar10 = (longlong *)0x0;
                                            local_100 = (longlong *)0x0;
                                            *_DAT_23ee287a0 = *_DAT_23ee287a0 + 1;
                                            goto LAB_23c630a30;
                                          }
                                          plVar14 = *(longlong **)(param_1 + 0x60);
                                          local_f0 = *(code **)(param_1 + 0x70);
                                          local_100 = (longlong *)0x0;
                                          plVar10 = (longlong *)0x0;
                                          uVar21 = 0x12a;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          pcVar18 = *(code **)(param_1 + 0x68);
                                        }
                                        goto LAB_23c631565;
                                      }
                                    }
                                  }
                                  plVar14 = *(longlong **)(param_1 + 0x60);
                                  pcVar18 = *(code **)(param_1 + 0x68);
                                  local_f0 = *(code **)(param_1 + 0x70);
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  *plVar12 = *plVar12 + -1;
                                  if (*plVar12 == 0) {
                                    FUN_23a334bc0(plVar12);
                                  }
                                  *plVar13 = *plVar13 + -1;
                                  if (*plVar13 == 0) {
                                    uVar21 = 0x12a;
                                    plVar10 = (longlong *)0x0;
                                    FUN_23a334bc0(plVar13);
                                    local_100 = (longlong *)0x0;
                                    goto LAB_23c631565;
                                  }
                                  uVar21 = 0x12a;
                                }
                                plVar10 = (longlong *)0x0;
                                local_100 = (longlong *)0x0;
                              }
                            }
                          }
                          else {
                            plVar10 = (longlong *)FUN_23e8bc2f0(plVar11,_DAT_23ee286b0);
                            if (plVar10 == (longlong *)0x0) {
                              plVar14 = *(longlong **)(param_1 + 0x60);
                              local_f0 = *(code **)(param_1 + 0x70);
                              local_100 = (longlong *)0x0;
                              plVar10 = (longlong *)0x0;
                              uVar21 = 0x12d;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              local_108 = (longlong *)0x0;
                              pcVar18 = *(code **)(param_1 + 0x68);
                            }
                            else {
                              iVar5 = FUN_23e97a530(plVar10,_DAT_23ee286f8);
                              lVar7 = *plVar10;
                              *plVar10 = lVar7 + -1;
                              if (lVar7 + -1 == 0) {
                                FUN_23a334bc0(plVar10);
                              }
                              lVar7 = _DAT_23ee287b0;
                              if (iVar5 == -1) {
                                local_f0 = *(code **)(param_1 + 0x70);
                                plVar14 = *(longlong **)(param_1 + 0x60);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                uVar21 = 0x12d;
                                plVar10 = (longlong *)0x0;
                                local_100 = (longlong *)0x0;
                                local_108 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                pcVar18 = *(code **)(param_1 + 0x68);
                              }
                              else if (iVar5 == 1) {
                                *(undefined4 *)(plVar2 + 5) = 0x12f;
                                plVar10 = (longlong *)
                                          FUN_23e915840(param_1,plVar1,_DAT_23ee287a8,
                                                        *(undefined8 *)(lVar7 + 0x18));
                                if (plVar10 != (longlong *)0x0) {
                                  lVar7 = *plVar10;
                                  *plVar10 = lVar7 + -1;
                                  if (lVar7 + -1 == 0) {
                                    FUN_23a334bc0(plVar10);
                                  }
                                  plVar12 = _DAT_23ee287b8;
                                  plVar10 = (longlong *)0x0;
                                  local_100 = (longlong *)0x0;
                                  *_DAT_23ee287b8 = *_DAT_23ee287b8 + 1;
                                  local_108 = (longlong *)0x0;
                                  goto LAB_23c630a30;
                                }
                                local_f0 = *(code **)(param_1 + 0x70);
                                plVar14 = *(longlong **)(param_1 + 0x60);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plVar10 = (longlong *)0x0;
                                uVar21 = 0x12f;
                                local_100 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                local_108 = (longlong *)0x0;
                                pcVar18 = *(code **)(param_1 + 0x68);
                              }
                              else {
                                plVar10 = (longlong *)FUN_23e8bc2f0(plVar11,_DAT_23ee286b0);
                                if (plVar10 == (longlong *)0x0) {
                                  plVar14 = *(longlong **)(param_1 + 0x60);
                                  local_100 = (longlong *)0x0;
                                  local_f0 = *(code **)(param_1 + 0x70);
                                  uVar21 = 0x132;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  plVar10 = (longlong *)0x0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  local_108 = (longlong *)0x0;
                                  pcVar18 = *(code **)(param_1 + 0x68);
                                }
                                else {
                                  iVar5 = FUN_23e97a530(plVar10,_DAT_23ee28708);
                                  lVar7 = *plVar10;
                                  *plVar10 = lVar7 + -1;
                                  if (lVar7 + -1 == 0) {
                                    FUN_23a334bc0(plVar10);
                                  }
                                  if (iVar5 == -1) {
                                    plVar14 = *(longlong **)(param_1 + 0x60);
                                    local_f0 = *(code **)(param_1 + 0x70);
                                    local_100 = (longlong *)0x0;
                                    plVar10 = (longlong *)0x0;
                                    uVar21 = 0x132;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    local_108 = (longlong *)0x0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    pcVar18 = *(code **)(param_1 + 0x68);
                                  }
                                  else if (iVar5 == 1) {
                                    *(undefined4 *)(plVar2 + 5) = 0x134;
                                    plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar11);
                                    if (plVar10 == (longlong *)0x0) {
                                      plVar14 = *(longlong **)(param_1 + 0x60);
                                      local_f0 = *(code **)(param_1 + 0x70);
                                      local_100 = (longlong *)0x0;
                                      plVar10 = (longlong *)0x0;
                                      uVar21 = 0x134;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      local_108 = (longlong *)0x0;
                                      pcVar18 = *(code **)(param_1 + 0x68);
                                    }
                                    else {
                                      plVar12 = (longlong *)FUN_23e8bc2f0(plVar10,DAT_23ed6ce40);
                                      lVar7 = *plVar10;
                                      *plVar10 = lVar7 + -1;
                                      if (lVar7 + -1 == 0) {
                                        FUN_23a334bc0();
                                      }
                                      if (plVar12 == (longlong *)0x0) {
                                        plVar14 = *(longlong **)(param_1 + 0x60);
                                        local_f0 = *(code **)(param_1 + 0x70);
                                        local_100 = (longlong *)0x0;
                                        uVar21 = 0x134;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        local_108 = (longlong *)0x0;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        plVar10 = (longlong *)0x0;
                                        pcVar18 = *(code **)(param_1 + 0x68);
                                      }
                                      else {
                                        *(undefined4 *)(plVar2 + 5) = 0x134;
                                        local_100 = (longlong *)FUN_23e9557e0(param_1,plVar12);
                                        *plVar12 = *plVar12 + -1;
                                        if (*plVar12 == 0) {
                                          FUN_23a334bc0(plVar12);
                                        }
                                        uVar19 = _DAT_23ee287c0;
                                        if (local_100 == (longlong *)0x0) {
                                          local_f0 = *(code **)(param_1 + 0x70);
                                          plVar14 = *(longlong **)(param_1 + 0x60);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          plVar10 = (longlong *)0x0;
                                          uVar21 = 0x134;
                                          local_108 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          pcVar18 = *(code **)(param_1 + 0x68);
                                        }
                                        else {
                                          plVar10 = (longlong *)
                                                    FUN_23e8bc2f0(local_100,DAT_23ed6ce98);
                                          if (plVar10 == (longlong *)0x0) {
                                            plVar14 = *(longlong **)(param_1 + 0x60);
                                            local_f0 = *(code **)(param_1 + 0x70);
                                            local_108 = (longlong *)0x0;
                                            uVar21 = 0x135;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            plVar10 = (longlong *)0x0;
                                            pcVar18 = *(code **)(param_1 + 0x68);
                                          }
                                          else {
                                            *(undefined4 *)(plVar2 + 5) = 0x135;
                                            plVar12 = (longlong *)FUN_23e91a870(param_1,plVar10);
                                            *plVar10 = *plVar10 + -1;
                                            if (*plVar10 == 0) {
                                              FUN_23a334bc0(plVar10);
                                            }
                                            if (plVar12 == (longlong *)0x0) {
                                              plVar14 = *(longlong **)(param_1 + 0x60);
                                              local_f0 = *(code **)(param_1 + 0x70);
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              plVar10 = (longlong *)0x0;
                                              uVar21 = 0x135;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              local_108 = (longlong *)0x0;
                                              pcVar18 = *(code **)(param_1 + 0x68);
                                            }
                                            else {
                                              iVar5 = PySequence_Contains(plVar12,uVar19);
                                              lVar7 = *plVar12;
                                              *plVar12 = lVar7 + -1;
                                              if (lVar7 + -1 == 0) {
                                                FUN_23a334bc0(plVar12);
                                              }
                                              uVar19 = _DAT_23ee287d0;
                                              plVar10 = _DAT_23ee287c8;
                                              if (iVar5 == -1) {
                                                plVar14 = *(longlong **)(param_1 + 0x60);
                                                local_f0 = *(code **)(param_1 + 0x70);
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                                uVar21 = 0x135;
                                                plVar10 = (longlong *)0x0;
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                local_108 = (longlong *)0x0;
                                                pcVar18 = *(code **)(param_1 + 0x68);
                                              }
                                              else {
                                                if (iVar5 == 1) {
                                                  *_DAT_23ee287c8 = *_DAT_23ee287c8 + 1;
                                                  goto LAB_23c6348e0;
                                                }
                                                plVar10 = (longlong *)
                                                          FUN_23e8bc2f0(local_100,DAT_23ed6ce98);
                                                if (plVar10 == (longlong *)0x0) {
                                                  plVar14 = *(longlong **)(param_1 + 0x60);
                                                  local_f0 = *(code **)(param_1 + 0x70);
                                                  local_108 = (longlong *)0x0;
                                                  uVar21 = 0x137;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  plVar10 = (longlong *)0x0;
                                                  pcVar18 = *(code **)(param_1 + 0x68);
                                                }
                                                else {
                                                  *(undefined4 *)(plVar2 + 5) = 0x137;
                                                  plVar12 = (longlong *)
                                                            FUN_23e91a870(param_1,plVar10);
                                                  *plVar10 = *plVar10 + -1;
                                                  if (*plVar10 == 0) {
                                                    FUN_23a334bc0(plVar10);
                                                  }
                                                  if (plVar12 == (longlong *)0x0) {
                                                    plVar14 = *(longlong **)(param_1 + 0x60);
                                                    local_f0 = *(code **)(param_1 + 0x70);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    plVar10 = (longlong *)0x0;
                                                    uVar21 = 0x137;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_108 = (longlong *)0x0;
                                                    pcVar18 = *(code **)(param_1 + 0x68);
                                                  }
                                                  else {
                                                    iVar5 = PySequence_Contains(plVar12,uVar19);
                                                    lVar7 = *plVar12;
                                                    *plVar12 = lVar7 + -1;
                                                    if (lVar7 + -1 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    uVar19 = _DAT_23ee287e0;
                                                    plVar10 = _DAT_23ee287d8;
                                                    if (iVar5 == -1) {
                                                      plVar14 = *(longlong **)(param_1 + 0x60);
                                                      local_f0 = *(code **)(param_1 + 0x70);
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      uVar21 = 0x137;
                                                      plVar10 = (longlong *)0x0;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      local_108 = (longlong *)0x0;
                                                      pcVar18 = *(code **)(param_1 + 0x68);
                                                    }
                                                    else {
                                                      if (iVar5 == 1) {
                                                        *_DAT_23ee287d8 = *_DAT_23ee287d8 + 1;
                                                        goto LAB_23c6348e0;
                                                      }
                                                      plVar10 = (longlong *)
                                                                FUN_23e8bc2f0(local_100,
                                                                              DAT_23ed6ce98);
                                                      if (plVar10 == (longlong *)0x0) {
                                                        plVar14 = *(longlong **)(param_1 + 0x60);
                                                        local_f0 = *(code **)(param_1 + 0x70);
                                                        local_108 = (longlong *)0x0;
                                                        uVar21 = 0x139;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        plVar10 = (longlong *)0x0;
                                                        pcVar18 = *(code **)(param_1 + 0x68);
                                                      }
                                                      else {
                                                        *(undefined4 *)(plVar2 + 5) = 0x139;
                                                        plVar12 = (longlong *)
                                                                  FUN_23e91a870(param_1,plVar10);
                                                        *plVar10 = *plVar10 + -1;
                                                        if (*plVar10 == 0) {
                                                          FUN_23a334bc0(plVar10);
                                                        }
                                                        if (plVar12 == (longlong *)0x0) {
                                                          plVar14 = *(longlong **)(param_1 + 0x60);
                                                          local_f0 = *(code **)(param_1 + 0x70);
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          plVar10 = (longlong *)0x0;
                                                          uVar21 = 0x139;
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          local_108 = (longlong *)0x0;
                                                          pcVar18 = *(code **)(param_1 + 0x68);
                                                        }
                                                        else {
                                                          iVar5 = PySequence_Contains(plVar12,uVar19
                                                                                     );
                                                          lVar7 = *plVar12;
                                                          *plVar12 = lVar7 + -1;
                                                          if (lVar7 + -1 == 0) {
                                                            FUN_23a334bc0(plVar12);
                                                          }
                                                          plVar10 = _DAT_23ee287e8;
                                                          if (iVar5 == -1) {
                                                            local_f0 = *(code **)(param_1 + 0x70);
                                                            plVar14 = *(longlong **)(param_1 + 0x60)
                                                            ;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            uVar21 = 0x139;
                                                            plVar10 = (longlong *)0x0;
                                                            local_108 = (longlong *)0x0;
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            pcVar18 = *(code **)(param_1 + 0x68);
                                                          }
                                                          else {
                                                            if (iVar5 == 1) {
                                                              *_DAT_23ee287e8 = *_DAT_23ee287e8 + 1;
                                                            }
                                                            else {
                                                              iVar5 = FUN_23a35f020(local_100);
                                                              if (iVar5 == -1) {
                                                                plVar14 = *(longlong **)
                                                                           (param_1 + 0x60);
                                                                local_f0 = *(code **)(param_1 + 0x70
                                                                                     );
                                                                *(undefined1 (*) [16])
                                                                 (param_1 + 0x60) =
                                                                     (undefined1  [16])0x0;
                                                                uVar21 = 0x13c;
                                                                plVar10 = (longlong *)0x0;
                                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                                local_108 = (longlong *)0x0;
                                                                pcVar18 = *(code **)(param_1 + 0x68)
                                                                ;
                                                                goto LAB_23c631565;
                                                              }
                                                              plVar10 = local_100;
                                                              if (iVar5 != 1) {
                                                                plVar10 = _DAT_23ee287f0;
                                                              }
                                                              *plVar10 = *plVar10 + 1;
                                                            }
LAB_23c6348e0:
                                                            *(undefined4 *)(plVar2 + 5) = 0x13d;
                                                            plVar12 = (longlong *)
                                                                      FUN_23e915840(param_1,plVar1,
                                                                                    _DAT_23ee287a8);
                                                            if (plVar12 != (longlong *)0x0) {
                                                              lVar7 = *plVar12;
                                                              *plVar12 = lVar7 + -1;
                                                              if (lVar7 + -1 == 0) {
                                                                FUN_23a334bc0(plVar12);
                                                              }
                                                              plVar12 = (longlong *)
                                                                        FUN_23e916ad0(*(undefined8 *
                                                                                       )(param_1 +
                                                                                        0x10),2);
                                                              pcVar18 = _Py_FalseStruct_exref;
                                                              local_108 = (longlong *)0x0;
                                                              *(longlong *)_Py_FalseStruct_exref =
                                                                   *(longlong *)
                                                                    _Py_FalseStruct_exref + 1;
                                                              plVar12[3] = (longlong)pcVar18;
                                                              *plVar10 = *plVar10 + 1;
                                                              plVar12[4] = (longlong)plVar10;
                                                              goto LAB_23c630a30;
                                                            }
                                                            plVar14 = *(longlong **)(param_1 + 0x60)
                                                            ;
                                                            local_f0 = *(code **)(param_1 + 0x70);
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            uVar21 = 0x13d;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            local_108 = (longlong *)0x0;
                                                            pcVar18 = *(code **)(param_1 + 0x68);
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
                                  else {
                                    plVar10 = (longlong *)FUN_23e8bc2f0(plVar11,_DAT_23ee286b0);
                                    if (plVar10 == (longlong *)0x0) {
                                      plVar14 = *(longlong **)(param_1 + 0x60);
                                      local_f0 = *(code **)(param_1 + 0x70);
                                      local_100 = (longlong *)0x0;
                                      plVar10 = (longlong *)0x0;
                                      uVar21 = 0x140;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      local_108 = (longlong *)0x0;
                                      pcVar18 = *(code **)(param_1 + 0x68);
                                    }
                                    else {
                                      iVar5 = FUN_23e97a530(plVar10,_DAT_23ee287f8);
                                      lVar7 = *plVar10;
                                      *plVar10 = lVar7 + -1;
                                      if (lVar7 + -1 == 0) {
                                        FUN_23a334bc0(plVar10);
                                      }
                                      if (iVar5 == -1) {
                                        local_f0 = *(code **)(param_1 + 0x70);
                                        plVar14 = *(longlong **)(param_1 + 0x60);
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        uVar21 = 0x140;
                                        plVar10 = (longlong *)0x0;
                                        local_100 = (longlong *)0x0;
                                        local_108 = (longlong *)0x0;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        pcVar18 = *(code **)(param_1 + 0x68);
                                      }
                                      else if (iVar5 == 1) {
                                        *(undefined4 *)(plVar2 + 5) = 0x142;
                                        plVar10 = (longlong *)
                                                  FUN_23e91bfe0(param_1,plVar11,_DAT_23ee28488);
                                        if (plVar10 == (longlong *)0x0) {
                                          local_f0 = *(code **)(param_1 + 0x70);
                                          plVar14 = *(longlong **)(param_1 + 0x60);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          plVar10 = (longlong *)0x0;
                                          uVar21 = 0x142;
                                          local_100 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          local_108 = (longlong *)0x0;
                                          pcVar18 = *(code **)(param_1 + 0x68);
                                        }
                                        else {
                                          plVar12 = (longlong *)FUN_23e8bc2f0(plVar10,DAT_23ed6ce40)
                                          ;
                                          lVar7 = *plVar10;
                                          *plVar10 = lVar7 + -1;
                                          if (lVar7 + -1 == 0) {
                                            FUN_23a334bc0(plVar10);
                                          }
                                          if (plVar12 == (longlong *)0x0) {
                                            plVar14 = *(longlong **)(param_1 + 0x60);
                                            local_f0 = *(code **)(param_1 + 0x70);
                                            local_100 = (longlong *)0x0;
                                            uVar21 = 0x142;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            local_108 = (longlong *)0x0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            plVar10 = (longlong *)0x0;
                                            pcVar18 = *(code **)(param_1 + 0x68);
                                          }
                                          else {
                                            *(undefined4 *)(plVar2 + 5) = 0x142;
                                            local_100 = (longlong *)
                                                        FUN_23e9557e0(param_1,plVar12,_DAT_23ee28800
                                                                     );
                                            *plVar12 = *plVar12 + -1;
                                            if (*plVar12 == 0) {
                                              FUN_23a334bc0(plVar12);
                                            }
                                            lVar7 = _DAT_23ee28808;
                                            if (local_100 == (longlong *)0x0) {
                                              plVar14 = *(longlong **)(param_1 + 0x60);
                                              local_108 = (longlong *)0x0;
                                              local_f0 = *(code **)(param_1 + 0x70);
                                              uVar21 = 0x142;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              plVar10 = (longlong *)0x0;
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              pcVar18 = *(code **)(param_1 + 0x68);
                                            }
                                            else {
                                              *(undefined4 *)(plVar2 + 5) = 0x145;
                                              plVar10 = (longlong *)
                                                        FUN_23e915840(param_1,plVar1,_DAT_23ee287a8,
                                                                      *(undefined8 *)(lVar7 + 0x18))
                                              ;
                                              if (plVar10 != (longlong *)0x0) {
                                                lVar7 = *plVar10;
                                                *plVar10 = lVar7 + -1;
                                                if (lVar7 + -1 == 0) {
                                                  FUN_23a334bc0(plVar10);
                                                }
                                                plVar12 = _DAT_23ee28810;
                                                plVar10 = (longlong *)0x0;
                                                local_108 = (longlong *)0x0;
                                                *_DAT_23ee28810 = *_DAT_23ee28810 + 1;
                                                goto LAB_23c630a30;
                                              }
                                              plVar14 = *(longlong **)(param_1 + 0x60);
                                              local_f0 = *(code **)(param_1 + 0x70);
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              plVar10 = (longlong *)0x0;
                                              uVar21 = 0x145;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              local_108 = (longlong *)0x0;
                                              pcVar18 = *(code **)(param_1 + 0x68);
                                            }
                                          }
                                        }
                                      }
                                      else {
                                        lVar7 = FUN_23ead5f40();
                                        if (lVar7 == 0) {
                                          plVar10 = (longlong *)0x0;
                                          uVar21 = 0x14b;
                                          FUN_23e915740(param_1,&local_78,DAT_23ee283f8);
                                          local_100 = (longlong *)0x0;
                                          local_108 = (longlong *)0x0;
                                          local_f0 = local_68;
                                          plVar14 = local_78;
                                          pcVar18 = pcStack_70;
                                        }
                                        else {
                                          plVar12 = (longlong *)FUN_23e8bc2f0(lVar7,_DAT_23ee28548);
                                          plVar10 = _DAT_23ee28818;
                                          if (plVar12 == (longlong *)0x0) {
                                            plVar14 = *(longlong **)(param_1 + 0x60);
                                            local_f0 = *(code **)(param_1 + 0x70);
                                            local_108 = (longlong *)0x0;
                                            plVar10 = (longlong *)0x0;
                                            uVar21 = 0x14b;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            local_100 = (longlong *)0x0;
                                            pcVar18 = *(code **)(param_1 + 0x68);
                                          }
                                          else {
                                            plVar13 = (longlong *)
                                                      FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),
                                                                    3);
                                            *plVar10 = *plVar10 + 1;
                                            uVar19 = _DAT_23ee286b0;
                                            plVar13[3] = (longlong)plVar10;
                                            plVar10 = (longlong *)FUN_23e8bc2f0(plVar11,uVar19);
                                            if (plVar10 != (longlong *)0x0) {
                                              lVar7 = FUN_23e94f9d0(param_1,plVar10,DAT_23ed6cd28);
                                              *plVar10 = *plVar10 + -1;
                                              if (*plVar10 == 0) {
                                                FUN_23a334bc0(plVar10);
                                              }
                                              if (lVar7 != 0) {
                                                plVar13[4] = lVar7;
                                                plVar10 = _DAT_23ee28820;
                                                *_DAT_23ee28820 = *_DAT_23ee28820 + 1;
                                                plVar13[5] = (longlong)plVar10;
                                                plVar10 = (longlong *)
                                                          PyUnicode_Join(DAT_23ed6cd28,plVar13);
                                                *plVar13 = *plVar13 + -1;
                                                if (*plVar13 == 0) {
                                                  FUN_23a334bc0(plVar13);
                                                }
                                                if (plVar10 == (longlong *)0x0) {
                                                  local_f0 = *(code **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  plVar14 = *(longlong **)(param_1 + 0x60);
                                                  pcVar18 = *(code **)(param_1 + 0x68);
                                                  lVar7 = *plVar12;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  *plVar12 = lVar7 + -1;
                                                  local_108 = (longlong *)0x0;
                                                  if (lVar7 + -1 == 0) {
                                                    plVar10 = (longlong *)0x0;
                                                    uVar21 = 0x14b;
                                                    FUN_23a334bc0();
                                                    local_100 = (longlong *)0x0;
                                                  }
                                                  else {
                                                    plVar10 = (longlong *)0x0;
                                                    uVar21 = 0x14b;
                                                    local_100 = (longlong *)0x0;
                                                  }
                                                }
                                                else {
                                                  *(undefined4 *)(plVar2 + 5) = 0x14b;
                                                  plVar14 = (longlong *)
                                                            FUN_23e914090(param_1,plVar12,plVar10);
                                                  lVar7 = *plVar12;
                                                  *plVar12 = lVar7 + -1;
                                                  if (lVar7 + -1 == 0) {
                                                    FUN_23a334bc0(plVar12);
                                                  }
                                                  lVar7 = *plVar10;
                                                  *plVar10 = lVar7 + -1;
                                                  if (lVar7 + -1 == 0) {
                                                    FUN_23a334bc0(plVar10);
                                                  }
                                                  if (plVar14 == (longlong *)0x0) {
                                                    plVar14 = *(longlong **)(param_1 + 0x60);
                                                    local_f0 = *(code **)(param_1 + 0x70);
                                                    local_100 = (longlong *)0x0;
                                                    uVar21 = 0x14b;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    local_108 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    plVar10 = (longlong *)0x0;
                                                    pcVar18 = *(code **)(param_1 + 0x68);
                                                  }
                                                  else {
                                                    *plVar14 = *plVar14 + -1;
                                                    if (*plVar14 == 0) {
                                                      FUN_23a334bc0(plVar14);
                                                    }
                                                    *(undefined4 *)(plVar2 + 5) = 0x14c;
                                                    plVar10 = (longlong *)
                                                              FUN_23e91bfe0(param_1,plVar1,
                                                                            DAT_23ee28568);
                                                    if (plVar10 == (longlong *)0x0) {
                                                      plVar14 = *(longlong **)(param_1 + 0x60);
                                                      local_100 = (longlong *)0x0;
                                                      local_f0 = *(code **)(param_1 + 0x70);
                                                      plVar10 = (longlong *)0x0;
                                                      uVar21 = 0x14c;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      local_108 = (longlong *)0x0;
                                                      pcVar18 = *(code **)(param_1 + 0x68);
                                                    }
                                                    else {
                                                      iVar5 = FUN_23a35f020(plVar10);
                                                      lVar7 = *plVar10 + -1;
                                                      if (iVar5 == -1) {
                                                        local_f0 = *(code **)(param_1 + 0x70);
                                                        plVar14 = *(longlong **)(param_1 + 0x60);
                                                        pcVar18 = *(code **)(param_1 + 0x68);
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        *plVar10 = lVar7;
                                                        if (lVar7 == 0) {
                                                          uVar21 = 0x14c;
                                                          plVar10 = (longlong *)0x0;
                                                          FUN_23a334bc0();
                                                          local_100 = (longlong *)0x0;
                                                          local_108 = (longlong *)0x0;
                                                        }
                                                        else {
                                                          uVar21 = 0x14c;
                                                          plVar10 = (longlong *)0x0;
                                                          local_100 = (longlong *)0x0;
                                                          local_108 = (longlong *)0x0;
                                                        }
                                                      }
                                                      else {
                                                        *plVar10 = lVar7;
                                                        if (lVar7 == 0) {
                                                          FUN_23a334bc0(plVar10);
                                                        }
                                                        if (iVar5 == 0) {
                                                          plVar12 = (longlong *)
                                                                    FUN_23e8bc2f0(plVar1,
                                                  _DAT_23ee287a8);
                                                  plVar10 = _DAT_23ee28838;
                                                  if (plVar12 == (longlong *)0x0) {
                                                    local_f0 = *(code **)(param_1 + 0x70);
                                                    plVar14 = *(longlong **)(param_1 + 0x60);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    plVar10 = (longlong *)0x0;
                                                    uVar21 = 0x14f;
                                                    local_108 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    local_100 = (longlong *)0x0;
                                                    pcVar18 = *(code **)(param_1 + 0x68);
                                                    goto LAB_23c631565;
                                                  }
                                                  plVar13 = (longlong *)
                                                            FUN_23e916ad0(*(undefined8 *)
                                                                           (param_1 + 0x10),3);
                                                  *plVar10 = *plVar10 + 1;
                                                  uVar19 = _DAT_23ee286b0;
                                                  plVar13[3] = (longlong)plVar10;
                                                  plVar10 = (longlong *)
                                                            FUN_23e8bc2f0(plVar11,uVar19);
                                                  if (plVar10 != (longlong *)0x0) {
                                                    lVar7 = FUN_23e94f9d0(param_1,plVar10,
                                                                          DAT_23ed6cd28);
                                                    *plVar10 = *plVar10 + -1;
                                                    if (*plVar10 == 0) {
                                                      FUN_23a334bc0(plVar10);
                                                    }
                                                    if (lVar7 != 0) {
                                                      plVar13[4] = lVar7;
                                                      plVar10 = _DAT_23ee28840;
                                                      *_DAT_23ee28840 = *_DAT_23ee28840 + 1;
                                                      plVar13[5] = (longlong)plVar10;
                                                      plVar10 = (longlong *)
                                                                PyUnicode_Join(DAT_23ed6cd28,plVar13
                                                                              );
                                                      *plVar13 = *plVar13 + -1;
                                                      if (*plVar13 == 0) {
                                                        FUN_23a334bc0(plVar13);
                                                      }
                                                      if (plVar10 == (longlong *)0x0) {
                                                        local_f0 = *(code **)(param_1 + 0x70);
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        plVar14 = *(longlong **)(param_1 + 0x60);
                                                        pcVar18 = *(code **)(param_1 + 0x68);
                                                        lVar7 = *plVar12;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        *plVar12 = lVar7 + -1;
                                                        local_108 = (longlong *)0x0;
                                                        if (lVar7 + -1 == 0) {
                                                          plVar10 = (longlong *)0x0;
                                                          FUN_23a334bc0();
                                                          local_100 = (longlong *)0x0;
                                                          uVar21 = 0x14f;
                                                        }
                                                        else {
                                                          plVar10 = (longlong *)0x0;
                                                          uVar21 = 0x14f;
                                                          local_100 = (longlong *)0x0;
                                                        }
                                                      }
                                                      else {
                                                        *(undefined4 *)(plVar2 + 5) = 0x14f;
                                                        plVar14 = (longlong *)
                                                                  FUN_23e914090(param_1,plVar12,
                                                                                plVar10);
                                                        lVar7 = *plVar12;
                                                        *plVar12 = lVar7 + -1;
                                                        if (lVar7 + -1 == 0) {
                                                          FUN_23a334bc0(plVar12);
                                                        }
                                                        lVar7 = *plVar10;
                                                        *plVar10 = lVar7 + -1;
                                                        if (lVar7 + -1 == 0) {
                                                          FUN_23a334bc0(plVar10);
                                                        }
                                                        if (plVar14 == (longlong *)0x0) {
                                                          plVar14 = *(longlong **)(param_1 + 0x60);
                                                          local_f0 = *(code **)(param_1 + 0x70);
                                                          local_100 = (longlong *)0x0;
                                                          uVar21 = 0x14f;
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          local_108 = (longlong *)0x0;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          plVar10 = (longlong *)0x0;
                                                          pcVar18 = *(code **)(param_1 + 0x68);
                                                        }
                                                        else {
                                                          *plVar14 = *plVar14 + -1;
                                                          if (*plVar14 == 0) {
                                                            FUN_23a334bc0(plVar14);
                                                          }
                                                          plVar12 = (longlong *)
                                                                    FUN_23e916ad0(*(undefined8 *)
                                                                                   (param_1 + 0x10),
                                                                                  2);
                                                          pcVar18 = _Py_FalseStruct_exref;
                                                          plVar10 = _DAT_23ee28848;
                                                          uVar19 = *(undefined8 *)(param_1 + 0x10);
                                                          plVar12[3] = (longlong)
                                                                       _Py_FalseStruct_exref;
                                                          *(longlong *)pcVar18 =
                                                               *(longlong *)pcVar18 + 1;
                                                          plVar13 = (longlong *)
                                                                    FUN_23e916ad0(uVar19,3);
                                                          uVar19 = _DAT_23ee286b0;
                                                          *plVar10 = *plVar10 + 1;
                                                          plVar13[3] = (longlong)plVar10;
                                                          plVar10 = (longlong *)
                                                                    FUN_23e8bc2f0(plVar11,uVar19);
                                                          if (plVar10 == (longlong *)0x0) {
LAB_23c634531:
                                                            plVar14 = *(longlong **)(param_1 + 0x60)
                                                            ;
                                                            pcVar18 = *(code **)(param_1 + 0x68);
                                                            local_f0 = *(code **)(param_1 + 0x70);
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            *plVar13 = *plVar13 + -1;
                                                            if (*plVar13 == 0) {
                                                              FUN_23a334bc0();
                                                            }
                                                          }
                                                          else {
                                                            lVar7 = FUN_23e94f9d0(param_1,plVar10);
                                                            *plVar10 = *plVar10 + -1;
                                                            if (*plVar10 == 0) {
                                                              FUN_23a334bc0();
                                                            }
                                                            if (lVar7 == 0) goto LAB_23c634531;
                                                            plVar13[4] = lVar7;
                                                            plVar10 = _DAT_23ee28850;
                                                            *_DAT_23ee28850 = *_DAT_23ee28850 + 1;
                                                            plVar13[5] = (longlong)plVar10;
                                                            lVar7 = PyUnicode_Join(DAT_23ed6cd28,
                                                                                   plVar13);
                                                            *plVar13 = *plVar13 + -1;
                                                            if (*plVar13 == 0) {
                                                              FUN_23a334bc0();
                                                            }
                                                            if (lVar7 != 0) goto LAB_23c631504;
                                                            local_f0 = *(code **)(param_1 + 0x70);
                                                            plVar14 = *(longlong **)(param_1 + 0x60)
                                                            ;
                                                            pcVar18 = *(code **)(param_1 + 0x68);
                                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                          }
                                                          *plVar12 = *plVar12 + -1;
                                                          if (*plVar12 == 0) {
                                                            FUN_23a334bc0();
                                                          }
                                                          uVar21 = 0x150;
                                                          plVar10 = (longlong *)0x0;
                                                          local_100 = (longlong *)0x0;
                                                          local_108 = (longlong *)0x0;
                                                        }
                                                      }
                                                      goto LAB_23c631565;
                                                    }
                                                  }
                                                  local_f0 = *(code **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  plVar14 = *(longlong **)(param_1 + 0x60);
                                                  pcVar18 = *(code **)(param_1 + 0x68);
                                                  lVar7 = *plVar12;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  *plVar12 = lVar7 + -1;
                                                  if (lVar7 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  *plVar13 = *plVar13 + -1;
                                                  if (*plVar13 == 0) {
                                                    uVar21 = 0x14f;
                                                    plVar10 = (longlong *)0x0;
                                                    FUN_23a334bc0(plVar13);
                                                    local_100 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                  }
                                                  else {
                                                    uVar21 = 0x14f;
                                                    plVar10 = (longlong *)0x0;
                                                    local_100 = (longlong *)0x0;
                                                    local_108 = (longlong *)0x0;
                                                  }
                                                  }
                                                  else {
                                                    plVar12 = (longlong *)
                                                              FUN_23e916ad0(*(undefined8 *)
                                                                             (param_1 + 0x10),2);
                                                    pcVar18 = _Py_TrueStruct_exref;
                                                    plVar10 = _DAT_23ee28828;
                                                    uVar19 = *(undefined8 *)(param_1 + 0x10);
                                                    plVar12[3] = (longlong)_Py_TrueStruct_exref;
                                                    *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
                                                    plVar13 = (longlong *)FUN_23e916ad0(uVar19,3);
                                                    uVar19 = _DAT_23ee286b0;
                                                    *plVar10 = *plVar10 + 1;
                                                    plVar13[3] = (longlong)plVar10;
                                                    plVar10 = (longlong *)
                                                              FUN_23e8bc2f0(plVar11,uVar19);
                                                    if (plVar10 == (longlong *)0x0) {
LAB_23c634263:
                                                      plVar14 = *(longlong **)(param_1 + 0x60);
                                                      pcVar18 = *(code **)(param_1 + 0x68);
                                                      local_f0 = *(code **)(param_1 + 0x70);
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *plVar13 = *plVar13 + -1;
                                                      if (*plVar13 == 0) {
                                                        FUN_23a334bc0(plVar13);
                                                      }
                                                    }
                                                    else {
                                                      lVar7 = FUN_23e94f9d0(param_1,plVar10);
                                                      *plVar10 = *plVar10 + -1;
                                                      if (*plVar10 == 0) {
                                                        FUN_23a334bc0(plVar10);
                                                      }
                                                      if (lVar7 == 0) goto LAB_23c634263;
                                                      plVar13[4] = lVar7;
                                                      plVar10 = _DAT_23ee28830;
                                                      *_DAT_23ee28830 = *_DAT_23ee28830 + 1;
                                                      plVar13[5] = (longlong)plVar10;
                                                      lVar7 = PyUnicode_Join(DAT_23ed6cd28,plVar13);
                                                      *plVar13 = *plVar13 + -1;
                                                      if (*plVar13 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                      if (lVar7 != 0) {
LAB_23c631504:
                                                        plVar12[4] = lVar7;
                                                        plVar10 = (longlong *)0x0;
                                                        local_100 = (longlong *)0x0;
                                                        local_108 = (longlong *)0x0;
                                                        goto LAB_23c630a30;
                                                      }
                                                      local_f0 = *(code **)(param_1 + 0x70);
                                                      plVar14 = *(longlong **)(param_1 + 0x60);
                                                      pcVar18 = *(code **)(param_1 + 0x68);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                    }
                                                    *plVar12 = *plVar12 + -1;
                                                    if (*plVar12 == 0) {
                                                      uVar21 = 0x14d;
                                                      plVar10 = (longlong *)0x0;
                                                      FUN_23a334bc0(plVar12);
                                                      local_100 = (longlong *)0x0;
                                                      local_108 = (longlong *)0x0;
                                                    }
                                                    else {
                                                      uVar21 = 0x14d;
                                                      plVar10 = (longlong *)0x0;
                                                      local_100 = (longlong *)0x0;
                                                      local_108 = (longlong *)0x0;
                                                    }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                                goto LAB_23c631565;
                                              }
                                            }
                                            local_f0 = *(code **)(param_1 + 0x70);
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            plVar14 = *(longlong **)(param_1 + 0x60);
                                            pcVar18 = *(code **)(param_1 + 0x68);
                                            lVar7 = *plVar12;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            *plVar12 = lVar7 + -1;
                                            if (lVar7 + -1 == 0) {
                                              FUN_23a334bc0();
                                            }
                                            *plVar13 = *plVar13 + -1;
                                            if (*plVar13 == 0) {
                                              uVar21 = 0x14b;
                                              plVar10 = (longlong *)0x0;
                                              FUN_23a334bc0(plVar13);
                                              local_100 = (longlong *)0x0;
                                              local_108 = (longlong *)0x0;
                                            }
                                            else {
                                              uVar21 = 0x14b;
                                              plVar10 = (longlong *)0x0;
                                              local_100 = (longlong *)0x0;
                                              local_108 = (longlong *)0x0;
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
                }
              }
              goto LAB_23c631565;
            }
          }
          plVar14 = *(longlong **)(param_1 + 0x60);
          pcVar18 = *(code **)(param_1 + 0x68);
          local_f0 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar11 = *plVar11 + -1;
          if (*plVar11 != 0) {
            uVar21 = 0x113;
            goto LAB_23c6320e6;
          }
          uVar21 = 0x113;
          (**(code **)(plVar11[1] + 0x30))(plVar11);
          goto LAB_23c631c9c;
        }
        plVar14 = *(longlong **)(param_1 + 0x60);
        pcVar18 = *(code **)(param_1 + 0x68);
        local_f0 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          plVar10 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          plVar6 = (longlong *)0x0;
          uVar21 = 0x111;
          (**(code **)(plVar8[1] + 0x30))(plVar8);
          local_100 = (longlong *)0x0;
          local_108 = (longlong *)0x0;
        }
        else {
          plVar10 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          plVar6 = (longlong *)0x0;
          uVar21 = 0x111;
          local_100 = (longlong *)0x0;
          local_108 = (longlong *)0x0;
        }
        goto LAB_23c631565;
      }
      plVar6 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar6 != (longlong *)0x0) {
        *plVar6 = *plVar6 + 1;
        DAT_23ed6a4c0 = plVar6;
        goto LAB_23c630cdd;
      }
      goto LAB_23c63337f;
    }
    FUN_23e915740(param_1,&local_78,DAT_23ee283f8);
    plVar6 = (longlong *)0x0;
    local_f0 = local_68;
    plVar14 = local_78;
    pcVar18 = pcStack_70;
LAB_23c631539:
    plVar10 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    local_100 = (longlong *)0x0;
    uVar21 = 0x111;
    local_108 = (longlong *)0x0;
    local_f8 = _PyRuntime_exref;
LAB_23c631565:
    local_d8 = *(longlong **)(param_1 + 0x138);
    local_98._8_8_ = pcVar18;
    local_98._0_8_ = plVar14;
    if (local_d8 != (longlong *)0x0) {
      *local_d8 = *local_d8 + 1;
    }
    pcVar18 = DAT_23ed6a4f8;
    local_e0 = &DAT_23ed6a4f8;
    local_88[0] = local_f0;
    if (local_f0 == (code *)0x0) {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar17 = *(code **)DAT_23ed6a4f8;
        *(undefined8 *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar17;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong *)(pcVar18 + 0x10) = 0;
      *(longlong **)(pcVar18 + 0x18) = plVar2;
      *plVar2 = *plVar2 + 1;
      lVar7 = *(longlong *)(local_f8 + 0x1f8);
      *(undefined4 *)(pcVar18 + 0x20) = 0xffffffff;
      lVar7 = *(longlong *)(lVar7 + 0x10);
      *(undefined4 *)(pcVar18 + 0x24) = uVar21;
      lVar7 = *(longlong *)(lVar7 + 0x2e8);
      lVar15 = *(longlong *)(pcVar18 + -8);
      plVar12 = *(longlong **)(lVar7 + 8);
      *plVar12 = (longlong)(pcVar18 + -0x10);
      *(longlong *)(pcVar18 + -0x10) = lVar7;
      *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar15 & 3) | (ulonglong)plVar12;
      *(code **)(lVar7 + 8) = pcVar18 + -0x10;
      if ((local_88[0] != (code *)0x0) &&
         (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1, *(longlong *)local_88[0] == 0))
      {
        (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))(local_88[0]);
      }
    }
    else {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar17 = *(code **)DAT_23ed6a4f8;
        *(undefined8 *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar17;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong **)(pcVar18 + 0x18) = plVar2;
      *plVar2 = *plVar2 + 1;
      lVar7 = *(longlong *)(local_f8 + 0x1f8);
      *(undefined4 *)(pcVar18 + 0x24) = uVar21;
      *(undefined4 *)(pcVar18 + 0x20) = 0xffffffff;
      lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0x10) + 0x2e8);
      lVar15 = *(longlong *)(pcVar18 + -8);
      plVar12 = *(longlong **)(lVar7 + 8);
      *plVar12 = (longlong)(pcVar18 + -0x10);
      *(longlong *)(pcVar18 + -0x10) = lVar7;
      *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar15 & 3) | (ulonglong)plVar12;
      *(code **)(lVar7 + 8) = pcVar18 + -0x10;
      *(code **)(pcVar18 + 0x10) = local_f0;
      *(longlong *)local_f0 = *(longlong *)local_f0 + 1;
      if ((local_88[0] != (code *)0x0) &&
         (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1, *(longlong *)local_88[0] == 0))
      {
        (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))(local_88[0]);
      }
    }
    pcVar17 = _Py_NoneStruct_exref;
    local_88[0] = pcVar18;
    if (((code *)local_98._0_8_ != (code *)0x0) && ((code *)local_98._0_8_ != _Py_NoneStruct_exref))
    {
      FUN_23e91b1b0(param_1,local_98,local_98 + 8,local_88);
    }
    plVar12 = *(longlong **)(local_98._8_8_ + 0x28);
    if (local_88[0] == pcVar17) {
      pcVar18 = (code *)0x0;
    }
    else {
      pcVar18 = local_88[0];
      if (local_88[0] != (code *)0x0) {
        *(longlong *)local_88[0] = *(longlong *)local_88[0] + 1;
      }
    }
    *(code **)(local_98._8_8_ + 0x28) = pcVar18;
    if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
      (**(code **)(plVar12[1] + 0x30))();
    }
    plVar12 = *(longlong **)(param_1 + 0x138);
    *(undefined8 *)(param_1 + 0x138) = local_98._8_8_;
    if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
      (**(code **)(plVar12[1] + 0x30))();
    }
    *(longlong *)local_98._0_8_ = *(longlong *)local_98._0_8_ + -1;
    if (*(longlong *)local_98._0_8_ == 0) {
      (**(code **)(*(longlong *)(local_98._0_8_ + 8) + 0x30))();
    }
    if ((local_88[0] != (code *)0x0) &&
       (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1, *(longlong *)local_88[0] == 0)) {
      (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))();
    }
    local_88[0] = (code *)0x0;
    local_98 = (undefined1  [16])0x0;
    uVar19 = *(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8);
    lVar7 = FUN_23ead5a00();
    if (lVar7 == 0) {
      FUN_23e915740(param_1,&local_78,_DAT_23ee28690);
      local_f0 = (code *)local_78;
      local_e8 = pcStack_70;
LAB_23c632761:
      in_R11 = *(code **)(param_1 + 0x138);
      *(longlong **)(param_1 + 0x138) = local_d8;
      pcVar18 = local_68;
joined_r0x00023c63277a:
      if (in_R11 != (code *)0x0) {
        *(longlong *)in_R11 = *(longlong *)in_R11 + -1;
        if (*(longlong *)in_R11 == 0) {
LAB_23c632548:
          iVar5 = 0x152;
LAB_23c63254e:
          (**(code **)(*(longlong *)(in_R11 + 8) + 0x30))(in_R11);
          if (pcVar18 == (code *)0x0) {
            if (iVar5 != 0) goto LAB_23c63258a;
            goto LAB_23c632586;
          }
        }
        else {
          iVar5 = 0x152;
joined_r0x00023c632793:
          if (pcVar18 == (code *)0x0) goto LAB_23c63258a;
        }
LAB_23c632180:
        pcVar17 = pcVar18;
        if (*(longlong **)(pcVar18 + 0x18) == plVar2) goto LAB_23c631de0;
        if (iVar5 == 0) {
          iVar5 = (int)plVar2[5];
        }
        goto LAB_23c631d3f;
      }
joined_r0x00023c6324fc:
      if (pcVar18 != (code *)0x0) {
        pcVar17 = pcVar18;
        if (plVar2 == *(longlong **)(pcVar18 + 0x18)) goto LAB_23c631de0;
        iVar5 = 0x152;
        goto LAB_23c631d3f;
      }
    }
    else {
      plVar12 = (longlong *)FUN_23e8bc2f0(lVar7,_DAT_23ee28740);
      if (plVar12 != (longlong *)0x0) {
        lVar7 = FUN_23e8bc2f0(plVar12,_DAT_23ee28748);
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        if (lVar7 == 0) {
          local_f0 = *(code **)(param_1 + 0x60);
          local_68 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          local_e8 = *(code **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23c632761;
        }
        lVar15 = *(longlong *)(param_1 + 0x10);
        plVar12 = *(longlong **)(lVar15 + 0xe20);
        if (plVar12 == (longlong *)0x0) {
          plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
        }
        else {
          lVar3 = plVar12[3];
          *(int *)(lVar15 + 0xebc) = *(int *)(lVar15 + 0xebc) + -1;
          *(longlong *)(lVar15 + 0xe20) = lVar3;
          *plVar12 = 1;
        }
        plVar12[4] = 0;
        lVar15 = *(longlong *)(*(longlong *)(*(longlong *)(local_f8 + 0x1f8) + 0x10) + 0x2e8);
        lVar3 = plVar12[-1];
        puVar20 = *(undefined8 **)(lVar15 + 8);
        *puVar20 = plVar12 + -2;
        plVar12[-2] = lVar15;
        plVar12[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar20;
        *(longlong **)(lVar15 + 8) = plVar12 + -2;
        plVar12[3] = lVar7;
        lVar7 = FUN_23ead5a00();
        if (lVar7 == 0) {
          FUN_23e915740(param_1,&local_78,_DAT_23ee28690);
          local_f0 = (code *)local_78;
          local_e8 = pcStack_70;
          pcVar18 = local_68;
LAB_23c632139:
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
            in_R11 = *(code **)(param_1 + 0x138);
            *(longlong **)(param_1 + 0x138) = local_d8;
          }
          else {
            in_R11 = *(code **)(param_1 + 0x138);
            *(longlong **)(param_1 + 0x138) = local_d8;
          }
          goto joined_r0x00023c6324f3;
        }
        plVar8 = (longlong *)FUN_23e8bc2f0(lVar7,_DAT_23ee28740);
        if (plVar8 == (longlong *)0x0) {
LAB_23c632110:
          local_f0 = *(code **)(param_1 + 0x60);
          pcVar18 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          local_e8 = *(code **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23c632139;
        }
        lVar7 = FUN_23e8bc2f0(plVar8,_DAT_23ee28758);
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))();
        }
        if (lVar7 == 0) goto LAB_23c632110;
        plVar12[4] = lVar7;
        iVar5 = FUN_23a35ebd0(param_1,uVar19,plVar12);
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        pcVar16 = *(code **)(param_1 + 0x138);
        in_R11 = pcVar16;
        if (iVar5 == -1) {
          local_f0 = *(code **)(param_1 + 0x60);
          pcVar18 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          local_e8 = *(code **)(param_1 + 0x68);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(longlong **)(param_1 + 0x138) = local_d8;
          goto joined_r0x00023c63277a;
        }
        plVar8 = plVar6;
        if (iVar5 != 0) {
          *(longlong *)pcVar16 = *(longlong *)pcVar16 + 1;
          lVar7 = FUN_23ead5f40();
          if (lVar7 == 0) {
            FUN_23e915740(param_1,&local_78,DAT_23ee283f8);
            iVar5 = 0x154;
            local_f0 = (code *)local_78;
            local_e8 = pcStack_70;
            pcVar18 = local_68;
          }
          else {
            plVar14 = (longlong *)FUN_23e8bc2f0(lVar7,_DAT_23ee28548);
            plVar12 = _DAT_23ee28858;
            if (plVar14 == (longlong *)0x0) {
LAB_23c632c4b:
              local_f0 = *(code **)(param_1 + 0x60);
              pcVar18 = *(code **)(param_1 + 0x70);
              iVar5 = 0x154;
              *(undefined8 *)(param_1 + 0x70) = 0;
              local_e8 = *(code **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
            else {
              lVar7 = *(longlong *)(param_1 + 0x10);
              plVar13 = *(longlong **)(lVar7 + 0xe28);
              if (plVar13 == (longlong *)0x0) {
                plVar13 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
              }
              else {
                lVar15 = plVar13[3];
                *(int *)(lVar7 + 0xec0) = *(int *)(lVar7 + 0xec0) + -1;
                *(longlong *)(lVar7 + 0xe28) = lVar15;
                *plVar13 = 1;
              }
              *(undefined1 (*) [16])(plVar13 + 4) = (undefined1  [16])0x0;
              lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(local_f8 + 0x1f8) + 0x10) + 0x2e8);
              lVar15 = plVar13[-1];
              puVar20 = *(undefined8 **)(lVar7 + 8);
              *puVar20 = plVar13 + -2;
              plVar13[-2] = lVar7;
              plVar13[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar20;
              *(longlong **)(lVar7 + 8) = plVar13 + -2;
              *plVar12 = *plVar12 + 1;
              plVar13[3] = (longlong)plVar12;
              pcVar18 = DAT_23ed6cd28;
              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                plVar12 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                iVar5 = (int)puVar20;
                if (plVar12 == (longlong *)0x0) {
LAB_23c63337f:
                  pcVar18 = (code *)0x0;
                  local_f0 = (code *)&DAT_23ed6cce0;
                  PyErr_PrintEx(0);
                  Py_Exit(1);
                  plVar6 = plVar8;
                  goto LAB_23c633392;
                }
                *plVar12 = *plVar12 + 1;
                DAT_23ed6a4c0 = plVar12;
              }
              pcStack_a0 = pcVar18;
              local_a8 = pcVar16;
              lVar7 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_a8);
              if (lVar7 == 0) {
                local_f0 = *(code **)(param_1 + 0x60);
                pcVar18 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                local_e8 = *(code **)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                *plVar13 = *plVar13 + -1;
                iVar5 = 0x154;
                if (*plVar13 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                  iVar5 = 0x154;
                }
              }
              else {
                plVar13[4] = lVar7;
                plVar12 = _DAT_23ee28820;
                *_DAT_23ee28820 = *_DAT_23ee28820 + 1;
                plVar13[5] = (longlong)plVar12;
                plVar12 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar13);
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                if (plVar12 == (longlong *)0x0) {
                  local_f0 = *(code **)(param_1 + 0x60);
                  pcVar18 = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  iVar5 = 0x154;
                  local_e8 = *(code **)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                    iVar5 = 0x154;
                  }
                }
                else {
                  *(undefined4 *)(plVar2 + 5) = 0x154;
                  plVar8 = (longlong *)FUN_23e914090(param_1,plVar14);
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  if (plVar8 == (longlong *)0x0) goto LAB_23c632c4b;
                  *plVar8 = *plVar8 + -1;
                  if (*plVar8 == 0) {
                    (**(code **)(plVar8[1] + 0x30))(plVar8);
                  }
                  *(undefined4 *)(plVar2 + 5) = 0x155;
                  plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23ee28568);
                  if (plVar12 == (longlong *)0x0) {
                    local_f0 = *(code **)(param_1 + 0x60);
                    pcVar18 = *(code **)(param_1 + 0x70);
                    iVar5 = 0x155;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    local_e8 = *(code **)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                  else {
                    iVar5 = FUN_23a35f020(plVar12);
                    lVar7 = *plVar12 + -1;
                    if (iVar5 == -1) {
                      local_f0 = *(code **)(param_1 + 0x60);
                      pcVar18 = *(code **)(param_1 + 0x70);
                      iVar5 = 0x155;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      local_e8 = *(code **)(param_1 + 0x68);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar12 = lVar7;
                      if (lVar7 == 0) {
                        FUN_23a334bc0(plVar12);
                        iVar5 = 0x155;
                      }
                    }
                    else {
                      *plVar12 = lVar7;
                      if (lVar7 == 0) {
                        (**(code **)(plVar12[1] + 0x30))(plVar12);
                      }
                      lVar7 = _DAT_23ee28870;
                      if (iVar5 == 0) {
                        *(undefined4 *)(plVar2 + 5) = 0x159;
                        plVar12 = (longlong *)
                                  FUN_23e915840(param_1,plVar1,_DAT_23ee287a8,
                                                *(undefined8 *)(lVar7 + 0x18));
                        if (plVar12 != (longlong *)0x0) {
                          *plVar12 = *plVar12 + -1;
                          if (*plVar12 == 0) {
                            (**(code **)(plVar12[1] + 0x30))();
                          }
                          plVar12 = _DAT_23ee28878;
                          *_DAT_23ee28878 = *_DAT_23ee28878 + 1;
LAB_23c631c2b:
                          *(longlong *)pcVar16 = *(longlong *)pcVar16 + -1;
                          if (*(longlong *)pcVar16 == 0) {
                            (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
                          }
                          goto LAB_23c63248a;
                        }
                        local_f0 = *(code **)(param_1 + 0x60);
                        pcVar18 = *(code **)(param_1 + 0x70);
                        iVar5 = 0x159;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        local_e8 = *(code **)(param_1 + 0x68);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      }
                      else {
                        lVar15 = FUN_23ead5f40();
                        lVar7 = _DAT_23ee28860;
                        if (lVar15 == 0) {
                          FUN_23e915740(param_1,&local_78,DAT_23ee283f8);
                          iVar5 = 0x156;
                          local_f0 = (code *)local_78;
                          local_e8 = pcStack_70;
                          pcVar18 = local_68;
                        }
                        else {
                          *(undefined4 *)(plVar2 + 5) = 0x156;
                          plVar12 = (longlong *)
                                    FUN_23e915840(param_1,lVar15,DAT_23ee28400,
                                                  *(undefined8 *)(lVar7 + 0x18));
                          if (plVar12 != (longlong *)0x0) {
                            *plVar12 = *plVar12 + -1;
                            if (*plVar12 == 0) {
                              (**(code **)(plVar12[1] + 0x30))(plVar12);
                            }
                            plVar12 = _DAT_23ee28868;
                            *_DAT_23ee28868 = *_DAT_23ee28868 + 1;
                            goto LAB_23c631c2b;
                          }
                          local_f0 = *(code **)(param_1 + 0x60);
                          pcVar18 = *(code **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          iVar5 = 0x156;
                          local_e8 = *(code **)(param_1 + 0x68);
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          *(longlong *)pcVar16 = *(longlong *)pcVar16 + -1;
          if (*(longlong *)pcVar16 == 0) {
            (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
            in_R11 = *(code **)(param_1 + 0x138);
            goto LAB_23c632bc7;
          }
LAB_23c632bf8:
          in_R11 = *(code **)(param_1 + 0x138);
          *(longlong **)(param_1 + 0x138) = local_d8;
          if (in_R11 == (code *)0x0) {
            if (pcVar18 == (code *)0x0) goto LAB_23c63258a;
            plVar12 = *(longlong **)(pcVar18 + 0x18);
            goto joined_r0x00023c632c23;
          }
LAB_23c632bdb:
          *(longlong *)in_R11 = *(longlong *)in_R11 + -1;
          if (*(longlong *)in_R11 != 0) goto joined_r0x00023c632793;
          goto LAB_23c63254e;
        }
        iVar5 = FUN_23a35ebd0(param_1,*(longlong *)(pcVar16 + 8),
                              *(undefined8 *)PyExc_Exception_exref);
        if (iVar5 != 0) {
          pcVar17 = *(code **)(param_1 + 0x138);
          *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
          lVar7 = FUN_23ead5f40();
          if (lVar7 == 0) {
            FUN_23e915740(param_1,&local_78,DAT_23ee283f8);
            iVar5 = 0x15d;
            local_f0 = (code *)local_78;
            local_e8 = pcStack_70;
            pcVar18 = local_68;
            goto LAB_23c632de2;
          }
          pcVar16 = (code *)FUN_23e8bc2f0(lVar7,DAT_23ee284c0);
          plVar12 = _DAT_23ee28880;
          if (pcVar16 == (code *)0x0) {
LAB_23c632e8b:
            local_f0 = *(code **)(param_1 + 0x60);
            pcVar18 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            local_e8 = *(code **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23c632ddc:
            iVar5 = 0x15d;
          }
          else {
            lVar7 = *(longlong *)(param_1 + 0x10);
            plVar14 = *(longlong **)(lVar7 + 0xe20);
            if (plVar14 == (longlong *)0x0) {
              plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
            }
            else {
              lVar15 = plVar14[3];
              *(int *)(lVar7 + 0xebc) = *(int *)(lVar7 + 0xebc) + -1;
              *(longlong *)(lVar7 + 0xe20) = lVar15;
              *plVar14 = 1;
            }
            plVar14[4] = 0;
            lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(local_f8 + 0x1f8) + 0x10) + 0x2e8);
            lVar15 = plVar14[-1];
            puVar20 = *(undefined8 **)(lVar7 + 8);
            *puVar20 = plVar14 + -2;
            plVar14[-2] = lVar7;
            plVar14[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar20;
            *(longlong **)(lVar7 + 8) = plVar14 + -2;
            *plVar12 = *plVar12 + 1;
            plVar14[3] = (longlong)plVar12;
            pcVar18 = DAT_23ed6cd28;
            if (DAT_23ed6a4c0 == (longlong *)0x0) {
              in_R11 = pcVar16;
              plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              iVar5 = (int)plVar12;
              if (plVar13 == (longlong *)0x0) goto LAB_23c63337f;
              *plVar13 = *plVar13 + 1;
              DAT_23ed6a4c0 = plVar13;
            }
            pcStack_a0 = pcVar18;
            local_a8 = pcVar17;
            lVar7 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_a8);
            if (lVar7 == 0) {
              local_f0 = *(code **)(param_1 + 0x60);
              pcVar18 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              local_e8 = *(code **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(longlong *)pcVar16 = *(longlong *)pcVar16 + -1;
              if (*(longlong *)pcVar16 == 0) {
                (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
              }
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
              goto LAB_23c632ddc;
            }
            plVar14[4] = lVar7;
            plVar12 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar14);
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            if (plVar12 == (longlong *)0x0) {
              local_f0 = *(code **)(param_1 + 0x60);
              pcVar18 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              iVar5 = 0x15d;
              local_e8 = *(code **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(longlong *)pcVar16 = *(longlong *)pcVar16 + -1;
              if (*(longlong *)pcVar16 == 0) {
                (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
                iVar5 = 0x15d;
              }
              goto LAB_23c632de2;
            }
            *(undefined4 *)(plVar2 + 5) = 0x15d;
            plVar14 = (longlong *)FUN_23e914090(param_1,pcVar16);
            *(longlong *)pcVar16 = *(longlong *)pcVar16 + -1;
            if (*(longlong *)pcVar16 == 0) {
              (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
            }
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            if (plVar14 == (longlong *)0x0) goto LAB_23c632e8b;
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            *(undefined4 *)(plVar2 + 5) = 0x15f;
            plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar1,DAT_23ee28568);
            if (plVar12 == (longlong *)0x0) {
              local_f0 = *(code **)(param_1 + 0x60);
              pcVar18 = *(code **)(param_1 + 0x70);
              iVar5 = 0x15f;
              *(undefined8 *)(param_1 + 0x70) = 0;
              local_e8 = *(code **)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
            else {
              iVar5 = FUN_23a35f020(plVar12);
              lVar7 = *plVar12 + -1;
              if (iVar5 == -1) {
                local_f0 = *(code **)(param_1 + 0x60);
                pcVar18 = *(code **)(param_1 + 0x70);
                iVar5 = 0x15f;
                *(undefined8 *)(param_1 + 0x70) = 0;
                local_e8 = *(code **)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar12 = lVar7;
                if (lVar7 == 0) {
                  FUN_23a334bc0(plVar12);
                  iVar5 = 0x15f;
                }
              }
              else {
                *plVar12 = lVar7;
                if (lVar7 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                plVar12 = _DAT_23ee28888;
                if (iVar5 != 0) {
                  *_DAT_23ee28888 = *_DAT_23ee28888 + 1;
LAB_23c632467:
                  lVar7 = *(longlong *)pcVar17;
                  *(longlong *)pcVar17 = lVar7 + -1;
                  if (lVar7 + -1 == 0) {
                    (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))(pcVar17);
                  }
LAB_23c63248a:
                  plVar2 = *(longlong **)(param_1 + 0x138);
                  *(longlong **)(param_1 + 0x138) = local_d8;
                  plVar8 = plVar9;
                  if ((plVar2 != (longlong *)0x0) && (*plVar2 = *plVar2 + -1, *plVar2 == 0)) {
                    (**(code **)(plVar2[1] + 0x30))();
                  }
LAB_23c630a30:
                  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                  plVar2 = *(longlong **)(lVar7 + 0x28);
                  plVar9 = (longlong *)plVar2[2];
                  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30)
                  ;
                  *(undefined4 *)(plVar2 + 8) = 0xffffffff;
                  if (plVar9 != (longlong *)0x0) {
                    plVar2[2] = 0;
                    *plVar9 = *plVar9 + -1;
                    if (*plVar9 == 0) {
                      (**(code **)(plVar9[1] + 0x30))();
                    }
                  }
                  *plVar2 = *plVar2 + -1;
                  if (*plVar2 == 0) {
                    (**(code **)(plVar2[1] + 0x30))(plVar2);
                  }
                  plVar2[0xf] = 0;
                  if ((plVar6 != (longlong *)0x0) && (*plVar6 = *plVar6 + -1, *plVar6 == 0)) {
                    (**(code **)(plVar6[1] + 0x30))(plVar6);
                  }
                  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
                    (**(code **)(plVar8[1] + 0x30))(plVar8);
                  }
                  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  if ((local_108 != (longlong *)0x0) &&
                     (lVar7 = *local_108, *local_108 = lVar7 + -1, lVar7 + -1 == 0)) {
                    (**(code **)(local_108[1] + 0x30))(local_108);
                  }
                  if ((local_100 != (longlong *)0x0) &&
                     (lVar7 = *local_100, *local_100 = lVar7 + -1, lVar7 + -1 == 0)) {
                    (**(code **)(local_100[1] + 0x30))(local_100);
                  }
                  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  *plVar1 = *plVar1 + -1;
                  if (*plVar1 != 0) {
                    return plVar12;
                  }
                  (**(code **)(plVar1[1] + 0x30))(plVar1);
                  return plVar12;
                }
                lVar7 = *(longlong *)(param_1 + 0x10);
                plVar12 = *(longlong **)(lVar7 + 0xe20);
                if (plVar12 == (longlong *)0x0) {
                  plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                  lVar7 = *(longlong *)(param_1 + 0x10);
                  plVar14 = *(longlong **)(lVar7 + 0xe20);
                }
                else {
                  plVar14 = (longlong *)plVar12[3];
                  *(int *)(lVar7 + 0xebc) = *(int *)(lVar7 + 0xebc) + -1;
                  *(longlong **)(lVar7 + 0xe20) = plVar14;
                  *plVar12 = 1;
                }
                plVar12[4] = 0;
                plVar13 = _DAT_23ee28890;
                lVar15 = *(longlong *)
                          (*(longlong *)(*(longlong *)(local_f8 + 0x1f8) + 0x10) + 0x2e8);
                lVar3 = plVar12[-1];
                puVar20 = *(undefined8 **)(lVar15 + 8);
                *puVar20 = plVar12 + -2;
                pcVar18 = _Py_FalseStruct_exref;
                plVar12[-2] = lVar15;
                plVar12[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar20;
                *(longlong **)(lVar15 + 8) = plVar12 + -2;
                *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
                plVar12[3] = (longlong)pcVar18;
                if (plVar14 == (longlong *)0x0) {
                  plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                }
                else {
                  lVar15 = plVar14[3];
                  *(int *)(lVar7 + 0xebc) = *(int *)(lVar7 + 0xebc) + -1;
                  *(longlong *)(lVar7 + 0xe20) = lVar15;
                  *plVar14 = 1;
                }
                plVar14[4] = 0;
                lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(local_f8 + 0x1f8) + 0x10) + 0x2e8)
                ;
                lVar15 = plVar14[-1];
                puVar20 = *(undefined8 **)(lVar7 + 8);
                *puVar20 = plVar14 + -2;
                plVar14[-2] = lVar7;
                plVar14[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar20;
                *(longlong **)(lVar7 + 8) = plVar14 + -2;
                *plVar13 = *plVar13 + 1;
                plVar14[3] = (longlong)plVar13;
                pcVar18 = (code *)FUN_23e8bd350(pcVar17);
                iVar5 = (int)puVar20;
                if (pcVar18 == (code *)0x0) {
LAB_23c6334d5:
                  local_f0 = *(code **)(param_1 + 0x60);
                  pcVar18 = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  local_e8 = *(code **)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    FUN_23a334bc0(plVar14);
                  }
                }
                else {
                  pcVar16 = DAT_23ed6cd28;
                  if (DAT_23ed6a4c0 == (longlong *)0x0) {
                    in_R11 = pcVar18;
                    plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                    if (plVar13 == (longlong *)0x0) goto LAB_23c63337f;
                    *plVar13 = *plVar13 + 1;
                    DAT_23ed6a4c0 = plVar13;
                  }
                  local_a8 = pcVar18;
                  pcStack_a0 = pcVar16;
                  lVar7 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_a8);
                  *(longlong *)pcVar18 = *(longlong *)pcVar18 + -1;
                  if (*(longlong *)pcVar18 == 0) {
                    (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))(pcVar18);
                  }
                  if (lVar7 == 0) goto LAB_23c6334d5;
                  plVar14[4] = lVar7;
                  lVar7 = PyUnicode_Join(DAT_23ed6cd28,plVar14);
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    FUN_23a334bc0(plVar14);
                  }
                  if (lVar7 != 0) {
                    plVar12[4] = lVar7;
                    goto LAB_23c632467;
                  }
                  local_f0 = *(code **)(param_1 + 0x60);
                  pcVar18 = *(code **)(param_1 + 0x70);
                  local_e8 = *(code **)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                }
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  FUN_23a334bc0(plVar12);
                }
                iVar5 = 0x161;
              }
            }
          }
LAB_23c632de2:
          lVar7 = *(longlong *)pcVar17;
          *(longlong *)pcVar17 = lVar7 + -1;
          if (lVar7 + -1 != 0) goto LAB_23c632bf8;
          (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))();
          in_R11 = *(code **)(param_1 + 0x138);
LAB_23c632bc7:
          *(longlong **)(param_1 + 0x138) = local_d8;
          if (in_R11 == (code *)0x0) {
            if (pcVar18 == (code *)0x0) goto LAB_23c63258a;
            plVar12 = *(longlong **)(pcVar18 + 0x18);
joined_r0x00023c632c23:
            pcVar17 = pcVar18;
            if (plVar12 == plVar2) goto LAB_23c631de0;
            goto LAB_23c631d3f;
          }
          goto LAB_23c632bdb;
        }
        in_R11 = *(code **)(param_1 + 0x138);
        if ((in_R11 == pcVar17) || (in_R11 == (code *)0x0)) {
          local_f0 = *(code **)PyExc_RuntimeError_exref;
          local_e8 = (code *)PyUnicode_FromString("No active exception to reraise");
          in_R11 = *(code **)(param_1 + 0x138);
          *(longlong *)local_f0 = *(longlong *)local_f0 + 1;
          *(longlong **)(param_1 + 0x138) = local_d8;
          if ((in_R11 == (code *)0x0) ||
             (*(longlong *)in_R11 = *(longlong *)in_R11 + -1, *(longlong *)in_R11 != 0)) {
            iVar5 = 0x110;
            goto LAB_23c63258a;
          }
          iVar5 = 0x110;
          pcVar18 = (code *)0x0;
          goto LAB_23c63254e;
        }
        local_f0 = *(code **)(in_R11 + 8);
        pcVar18 = *(code **)(in_R11 + 0x28);
        *(longlong *)in_R11 = *(longlong *)in_R11 + 1;
        *(longlong *)local_f0 = *(longlong *)local_f0 + 1;
        iVar5 = 0;
        if (pcVar18 != (code *)0x0) {
          *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
          if (plVar2 == *(longlong **)(pcVar18 + 0x18)) {
            *(undefined4 *)(plVar2 + 5) = *(undefined4 *)(pcVar18 + 0x24);
          }
          *(longlong **)(param_1 + 0x138) = local_d8;
          *(longlong *)in_R11 = *(longlong *)in_R11 + -1;
          local_e8 = in_R11;
          if (*(longlong *)in_R11 == 0) goto LAB_23c63254e;
          goto LAB_23c632180;
        }
LAB_23c633392:
        *(longlong **)(param_1 + 0x138) = local_d8;
        *(longlong *)in_R11 = *(longlong *)in_R11 + -1;
        local_e8 = in_R11;
        if (*(longlong *)in_R11 == 0) goto LAB_23c63254e;
LAB_23c632586:
        iVar5 = (int)plVar2[5];
        goto LAB_23c63258a;
      }
      local_f0 = *(code **)(param_1 + 0x60);
      in_R11 = *(code **)(param_1 + 0x138);
      pcVar18 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      local_e8 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(longlong **)(param_1 + 0x138) = local_d8;
joined_r0x00023c6324f3:
      if (in_R11 == (code *)0x0) goto joined_r0x00023c6324fc;
      *(longlong *)in_R11 = *(longlong *)in_R11 + -1;
      if (*(longlong *)in_R11 == 0) goto LAB_23c632548;
      if (pcVar18 != (code *)0x0) {
        iVar5 = 0x152;
        goto LAB_23c632180;
      }
    }
    iVar5 = 0x152;
  }
LAB_23c63258a:
  pcVar17 = *local_e0;
  if (pcVar17 == (code *)0x0) {
    pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    *local_e0 = *(code **)pcVar17;
    *(longlong *)pcVar17 = 1;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong *)(pcVar17 + 0x10) = 0;
  *(longlong **)(pcVar17 + 0x18) = plVar2;
  *plVar2 = *plVar2 + 1;
  lVar7 = *(longlong *)(local_f8 + 0x1f8);
  *(int *)(pcVar17 + 0x24) = iVar5;
  lVar7 = *(longlong *)(lVar7 + 0x10);
  *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
  lVar7 = *(longlong *)(lVar7 + 0x2e8);
  lVar15 = *(longlong *)(pcVar17 + -8);
  puVar20 = *(undefined8 **)(lVar7 + 8);
  *puVar20 = pcVar17 + -0x10;
  *(longlong *)(pcVar17 + -0x10) = lVar7;
  *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar20;
  *(code **)(lVar7 + 8) = pcVar17 + -0x10;
LAB_23c631de0:
  FUN_23e8bba40(plVar2,"oooooooNo",plVar1,plVar6,plVar9,plVar11,local_108,local_100,plVar10,0,0);
  if (_DAT_23ee29c80 == plVar2) {
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    _DAT_23ee29c80 = (longlong *)0x0;
  }
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar2 = *(longlong **)(lVar7 + 0x28);
  plVar12 = (longlong *)plVar2[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
  *(undefined4 *)(plVar2 + 8) = 0xffffffff;
  if (plVar12 != (longlong *)0x0) {
    plVar2[2] = 0;
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))();
    }
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  plVar2[0xf] = 0;
  if ((plVar6 != (longlong *)0x0) && (*plVar6 = *plVar6 + -1, *plVar6 == 0)) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((local_108 != (longlong *)0x0) &&
     (lVar7 = *local_108, *local_108 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(local_108[1] + 0x30))(local_108);
  }
  if ((local_100 != (longlong *)0x0) &&
     (lVar7 = *local_100, *local_100 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(local_100[1] + 0x30))(local_100);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,local_f0,local_e8,pcVar17);
  return (longlong *)0x0;
}
