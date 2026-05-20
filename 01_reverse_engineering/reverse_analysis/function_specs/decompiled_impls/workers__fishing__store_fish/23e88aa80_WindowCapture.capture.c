/* ===== 23e88aa80 workers.fishing.store_fish:163 ===== */
/* ghidra_name=FUN_23e88aa80 entry=23e88aa80 size=6330 */

code * FUN_23e88aa80(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  char cVar5;
  int iVar6;
  undefined8 uVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong *plVar12;
  undefined8 uVar13;
  longlong *plVar14;
  code *pcVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  longlong *local_88;
  undefined8 uStack_80;
  undefined1 local_78 [16];
  longlong *local_68;
  
  plVar8 = DAT_23eede670;
  plVar1 = (longlong *)*param_3;
  local_68 = (longlong *)0x0;
  local_78 = (undefined1  [16])0x0;
  if (DAT_23eede670 == (longlong *)0x0) {
LAB_23e88aad7:
    DAT_23eede670 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eede668,DAT_23eede708,0x18);
  }
  else {
    lVar10 = *DAT_23eede670;
    if (1 < lVar10) {
      *DAT_23eede670 = lVar10 + -1;
      goto LAB_23e88aad7;
    }
    if (DAT_23eede670[2] != 0) {
      *DAT_23eede670 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e88aad7;
    }
  }
  plVar3 = DAT_23eede670;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar8 = DAT_23eede670 + 9;
  lVar2 = *(longlong *)(lVar10 + 8);
  DAT_23eede670[0xf] = lVar2;
  *(longlong **)(lVar10 + 8) = plVar8;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  uVar7 = FUN_23a3a0d40(DAT_23ed6cf28);
  *(undefined4 *)(plVar3 + 5) = 0xa5;
  plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar7,DAT_23eedca48);
  if (plVar8 == (longlong *)0x0) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    plVar9 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar16 = 0xa5;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar8 = (longlong *)0x0;
LAB_23e88b3cf:
    uVar17 = uVar16;
    if (local_68 == (longlong *)0x0) {
LAB_23e88ad70:
      plVar12 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar11 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar11;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar15 = _PyRuntime_exref;
      plVar12[3] = (longlong)plVar3;
      plVar12[2] = 0;
      *plVar3 = *plVar3 + 1;
      lVar10 = *(longlong *)(pcVar15 + 0x1f8);
      *(undefined4 *)(plVar12 + 4) = 0xffffffff;
      lVar10 = *(longlong *)(lVar10 + 0x10);
      *(undefined4 *)((longlong)plVar12 + 0x24) = uVar16;
      lVar10 = *(longlong *)(lVar10 + 0x2e8);
      lVar2 = plVar12[-1];
      puVar4 = *(undefined8 **)(lVar10 + 8);
      *puVar4 = plVar12 + -2;
      plVar12[-2] = lVar10;
      plVar12[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
      *(longlong **)(lVar10 + 8) = plVar12 + -2;
      if ((local_68 != (longlong *)0x0) && (*local_68 = *local_68 + -1, *local_68 == 0)) {
        (**(code **)(local_68[1] + 0x30))(local_68);
      }
      goto LAB_23e88b491;
    }
  }
  else {
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eedca10);
    if (plVar8 == (longlong *)0x0) {
      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      local_68 = *(longlong **)(param_1 + 0x70);
      plVar9 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar16 = 0xa6;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar8 = (longlong *)0x0;
      goto LAB_23e88b3cf;
    }
    *(undefined4 *)(plVar3 + 5) = 0xa6;
    plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar8,DAT_23eedca50);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (plVar9 != (longlong *)0x0) {
      iVar6 = FUN_23a35f020(plVar9);
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      if (iVar6 == -1) {
        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_68 = *(longlong **)(param_1 + 0x70);
        plVar9 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar16 = 0xa6;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e88b3cf;
      }
      if (iVar6 == 0) {
        uVar7 = FUN_23a3a0d40(DAT_23ed6cf28);
        *(undefined4 *)(plVar3 + 5) = 0xa7;
        plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar7,DAT_23eedca58);
        if (plVar8 == (longlong *)0x0) {
          local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          local_68 = *(longlong **)(param_1 + 0x70);
          plVar9 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar16 = 0xa7;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar8 = (longlong *)0x0;
          goto LAB_23e88b3cf;
        }
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        plVar9 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        lVar10 = *(longlong *)_Py_FalseStruct_exref;
LAB_23e88ac5e:
        pcVar15 = _Py_FalseStruct_exref;
        *(longlong *)_Py_FalseStruct_exref = lVar10 + 1;
        lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar3 = *(longlong **)(lVar10 + 0x28);
        plVar12 = (longlong *)plVar3[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
        *(undefined4 *)(plVar3 + 8) = 0xffffffff;
        if (plVar12 != (longlong *)0x0) {
          plVar3[2] = 0;
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))();
          }
        }
        *plVar3 = *plVar3 + -1;
        if (*plVar3 == 0) {
          (**(code **)(plVar3[1] + 0x30))(plVar3);
        }
        plVar3[0xf] = 0;
        if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        if (plVar9 == (longlong *)0x0) goto LAB_23e88acdd;
LAB_23e88accd:
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
LAB_23e88acdd:
        *plVar1 = *plVar1 + -1;
        if (*plVar1 != 0) {
          return pcVar15;
        }
        (**(code **)(plVar1[1] + 0x30))(plVar1);
        return pcVar15;
      }
      plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eedca10);
      if (plVar8 == (longlong *)0x0) {
LAB_23e88b3a0:
        plVar11 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar7 = *(undefined8 *)(param_1 + 0x60);
        uVar13 = *(undefined8 *)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      else {
        *(undefined4 *)(plVar3 + 5) = 0xab;
        plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar8,DAT_23eedca60);
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        if (plVar9 == (longlong *)0x0) goto LAB_23e88b3a0;
        plVar12 = (longlong *)FUN_23a388310(plVar9);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        if (plVar12 == (longlong *)0x0) goto LAB_23e88b3a0;
        plVar8 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
        if ((plVar8 == (longlong *)0x0) &&
           (plVar8 = (longlong *)FUN_23a3c1b70(param_1,local_78,0,2), plVar8 == (longlong *)0x0)) {
          plVar9 = (longlong *)0x0;
        }
        else {
          plVar9 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
          if (((plVar9 != (longlong *)0x0) ||
              (plVar9 = (longlong *)FUN_23a3c1b70(param_1,local_78,1,2), plVar9 != (longlong *)0x0))
             && (cVar5 = FUN_23a3884a0(param_1,local_78,plVar12,2), cVar5 != '\0')) {
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            uVar7 = FUN_23a3a0d40(DAT_23ed6cf28);
            plVar11 = DAT_23eedca68;
            lVar10 = *(longlong *)(param_1 + 0x10);
            plVar12 = *(longlong **)(lVar10 + 0xe30);
            if (plVar12 == (longlong *)0x0) {
              plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,4);
            }
            else {
              lVar2 = plVar12[3];
              *(int *)(lVar10 + 0xec4) = *(int *)(lVar10 + 0xec4) + -1;
              *(longlong *)(lVar10 + 0xe30) = lVar2;
              *plVar12 = 1;
            }
            pcVar15 = _PyRuntime_exref;
            plVar12[6] = 0;
            *(undefined1 (*) [16])(plVar12 + 4) = (undefined1  [16])0x0;
            lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar15 + 0x1f8) + 0x10) + 0x2e8);
            lVar2 = plVar12[-1];
            puVar4 = *(undefined8 **)(lVar10 + 8);
            *puVar4 = plVar12 + -2;
            plVar12[-2] = lVar10;
            plVar12[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
            *(longlong **)(lVar10 + 8) = plVar12 + -2;
            plVar14 = DAT_23ed6a4c0;
            *plVar11 = *plVar11 + 1;
            plVar12[3] = (longlong)plVar11;
            uVar13 = DAT_23ed6cd28;
            if (plVar14 == (longlong *)0x0) {
              plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              if (plVar14 != (longlong *)0x0) {
                *plVar14 = *plVar14 + 1;
                DAT_23ed6a4c0 = plVar14;
                goto LAB_23e88aff7;
              }
LAB_23e88c056:
              PyErr_PrintEx(0);
              Py_Exit(1);
LAB_23e88c069:
              local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_68 = *(longlong **)(param_1 + 0x70);
              uVar16 = 0xba;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e88b3cf;
            }
LAB_23e88aff7:
            uStack_80 = uVar13;
            local_88 = plVar8;
            lVar10 = FUN_23e94ed00(param_1,plVar14,&local_88);
            if (lVar10 == 0) {
LAB_23e88b7b8:
              local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_68 = *(longlong **)(param_1 + 0x70);
              uVar16 = 0xac;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar12 = *plVar12 + -1;
              lVar10 = *plVar12;
            }
            else {
              plVar12[4] = lVar10;
              plVar11 = DAT_23eedca70;
              *DAT_23eedca70 = *DAT_23eedca70 + 1;
              plVar12[5] = (longlong)plVar11;
              uVar13 = DAT_23ed6cd28;
              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                if (plVar11 == (longlong *)0x0) goto LAB_23e88c056;
                *plVar11 = *plVar11 + 1;
                DAT_23ed6a4c0 = plVar11;
              }
              uStack_80 = uVar13;
              local_88 = plVar9;
              lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_88);
              if (lVar10 == 0) goto LAB_23e88b7b8;
              plVar12[6] = lVar10;
              plVar11 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              if (plVar11 == (longlong *)0x0) {
LAB_23e88b750:
                local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                local_68 = *(longlong **)(param_1 + 0x70);
                uVar16 = 0xac;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e88b3cf;
              }
              *(undefined4 *)(plVar3 + 5) = 0xac;
              plVar12 = (longlong *)FUN_23e914090(param_1,uVar7);
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              if (plVar12 == (longlong *)0x0) goto LAB_23e88b750;
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              iVar6 = FUN_23e97a530(plVar8,DAT_23eedca78);
              if (iVar6 == -1) {
LAB_23e88bf50:
                local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                local_68 = *(longlong **)(param_1 + 0x70);
                uVar16 = 0xae;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e88b3cf;
              }
              if (iVar6 == 1) {
                iVar6 = FUN_23e97a530(plVar9,DAT_23eedca80);
                if (iVar6 == -1) goto LAB_23e88bf50;
                if (iVar6 != 1) goto LAB_23e88b123;
                cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eedca18,DAT_23eedca88);
                if (cVar5 == '\0') {
                  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_68 = *(longlong **)(param_1 + 0x70);
                  uVar16 = 0xaf;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e88b3cf;
                }
                lVar10 = *(longlong *)(DAT_23eedc7f0 + 0x20);
                if (*(char *)(lVar10 + 10) == '\0') {
                  plVar12 = (longlong *)FUN_23a37a020(DAT_23eedc7f0,DAT_23eedca90);
                  if (plVar12 == (longlong *)0x0) goto LAB_23e88c0f8;
                  lVar10 = *plVar12;
LAB_23e88c0ef:
                  if (lVar10 == 0) goto LAB_23e88c0f8;
                }
                else {
                  iVar6 = *(int *)(lVar10 + 0xc);
                  if (*(int *)(lVar10 + 0xc) == 0) {
                    *(int *)(lVar10 + 0xc) = DAT_23ec1555c;
                    iVar6 = DAT_23ec1555c;
                    DAT_23ec1555c = DAT_23ec1555c + 1;
                  }
                  if (DAT_23ec15544 != iVar6) {
                    DAT_23ec15544 = iVar6;
                    DAT_23eede658 =
                         FUN_23e8cbd60(lVar10,DAT_23eedca90,*(undefined8 *)(DAT_23eedca90 + 0x18));
                  }
                  if (-1 < DAT_23eede658) {
                    lVar2 = lVar10 + 0x20 + (1L << (*(byte *)(lVar10 + 9) & 0x3f));
                    if (*(longlong *)(lVar2 + 8 + DAT_23eede658 * 0x10) != 0) goto LAB_23e88ba0d;
                    DAT_23eede658 =
                         FUN_23e8cbd60(lVar10,DAT_23eedca90,*(undefined8 *)(DAT_23eedca90 + 0x18));
                    if (-1 < DAT_23eede658) {
                      lVar10 = *(longlong *)(lVar2 + 8 + DAT_23eede658 * 0x10);
                      goto LAB_23e88c0ef;
                    }
                  }
LAB_23e88c0f8:
                  plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eedca90);
                  if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
                    uVar16 = 0xb0;
                    FUN_23e915740(param_1,local_78,DAT_23eedca90);
                    goto LAB_23e88b3cf;
                  }
                }
LAB_23e88ba0d:
                cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eedca20);
                if (cVar5 == '\0') {
                  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_68 = *(longlong **)(param_1 + 0x70);
                  uVar16 = 0xb0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                }
                else {
                  cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eedcaa0,DAT_23eedca98);
                  if (cVar5 == '\0') {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar16 = 0xb1;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                  else {
                    uVar7 = FUN_23a3a0d40(DAT_23ed6cf28);
                    *(undefined4 *)(plVar3 + 5) = 0xb2;
                    plVar12 = (longlong *)FUN_23e94bb80(param_1,uVar7,DAT_23eedcaa8);
                    if (plVar12 == (longlong *)0x0) {
                      local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                      local_68 = *(longlong **)(param_1 + 0x70);
                      uVar16 = 0xb2;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    }
                    else {
LAB_23e88ba73:
                      *plVar12 = *plVar12 + -1;
                      if (*plVar12 == 0) {
                        FUN_23a334bc0();
                      }
                      uVar13 = FUN_23a3a0d40(DAT_23ed6cf28);
                      plVar12 = DAT_23eedcaf0;
                      plVar11 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),8);
                      *plVar12 = *plVar12 + 1;
                      uVar7 = DAT_23eedca20;
                      plVar11[3] = (longlong)plVar12;
                      plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,uVar7);
                      if (plVar12 == (longlong *)0x0) {
LAB_23e88c097:
                        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                        local_68 = *(longlong **)(param_1 + 0x70);
                        uVar16 = 0xbd;
                      }
                      else {
                        plVar14 = (longlong *)FUN_23a38cc10(param_1,plVar12,DAT_23eedca70);
                        *plVar12 = *plVar12 + -1;
                        if (*plVar12 == 0) {
                          FUN_23a334bc0();
                        }
                        if (plVar14 == (longlong *)0x0) goto LAB_23e88c097;
                        lVar10 = FUN_23e94f9d0(param_1,plVar14,DAT_23ed6cd28);
                        *plVar14 = *plVar14 + -1;
                        if (*plVar14 == 0) {
                          FUN_23a334bc0();
                        }
                        plVar12 = DAT_23eedcaf8;
                        if (lVar10 == 0) goto LAB_23e88c097;
                        plVar11[4] = lVar10;
                        uVar7 = DAT_23eedca20;
                        *plVar12 = *plVar12 + 1;
                        plVar11[5] = (longlong)plVar12;
                        plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,uVar7);
                        if (plVar12 == (longlong *)0x0) goto LAB_23e88c097;
                        plVar14 = (longlong *)FUN_23a38cc10(param_1,plVar12,DAT_23eedcb00);
                        *plVar12 = *plVar12 + -1;
                        if (*plVar12 == 0) {
                          FUN_23a334bc0();
                        }
                        if (plVar14 == (longlong *)0x0) goto LAB_23e88c097;
                        lVar10 = FUN_23e94f9d0(param_1,plVar14,DAT_23ed6cd28);
                        *plVar14 = *plVar14 + -1;
                        if (*plVar14 == 0) {
                          FUN_23a334bc0();
                        }
                        plVar12 = DAT_23eedcb08;
                        if (lVar10 == 0) goto LAB_23e88c097;
                        plVar11[6] = lVar10;
                        uVar7 = DAT_23eedca20;
                        *plVar12 = *plVar12 + 1;
                        plVar11[7] = (longlong)plVar12;
                        plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,uVar7);
                        if (plVar12 != (longlong *)0x0) {
                          plVar14 = (longlong *)FUN_23a38cc10(param_1,plVar12,DAT_23eedcb10);
                          *plVar12 = *plVar12 + -1;
                          if (*plVar12 == 0) {
                            FUN_23a334bc0();
                          }
                          if (plVar14 != (longlong *)0x0) {
                            lVar10 = FUN_23e94f9d0(param_1,plVar14,DAT_23ed6cd28);
                            *plVar14 = *plVar14 + -1;
                            if (*plVar14 == 0) {
                              FUN_23a334bc0();
                            }
                            plVar12 = DAT_23eedcb18;
                            if (lVar10 != 0) {
                              plVar11[8] = lVar10;
                              uVar7 = DAT_23eedca20;
                              *plVar12 = *plVar12 + 1;
                              plVar11[9] = (longlong)plVar12;
                              plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,uVar7);
                              if (plVar12 != (longlong *)0x0) {
                                plVar14 = (longlong *)FUN_23a38cc10(param_1,plVar12,DAT_23eedcb20);
                                *plVar12 = *plVar12 + -1;
                                if (*plVar12 == 0) {
                                  FUN_23a334bc0();
                                }
                                if (plVar14 != (longlong *)0x0) {
                                  lVar10 = FUN_23e94f9d0(param_1,plVar14,DAT_23ed6cd28);
                                  *plVar14 = *plVar14 + -1;
                                  if (*plVar14 == 0) {
                                    FUN_23a334bc0();
                                  }
                                  uVar7 = DAT_23ed6cd28;
                                  if (lVar10 != 0) {
                                    plVar11[10] = lVar10;
                                    plVar12 = (longlong *)PyUnicode_Join(uVar7);
                                    *plVar11 = *plVar11 + -1;
                                    if (*plVar11 == 0) {
                                      FUN_23a334bc0(plVar11);
                                    }
                                    if (plVar12 != (longlong *)0x0) {
                                      *(undefined4 *)(plVar3 + 5) = 0xbd;
                                      plVar11 = (longlong *)FUN_23e914090(param_1,uVar13,plVar12);
                                      *plVar12 = *plVar12 + -1;
                                      if (*plVar12 == 0) {
                                        FUN_23a334bc0(plVar12);
                                      }
                                      if (plVar11 != (longlong *)0x0) {
                                        *plVar11 = *plVar11 + -1;
                                        if (*plVar11 == 0) {
                                          FUN_23a334bc0(plVar11);
                                        }
                                        *(undefined4 *)(plVar3 + 5) = 0xc1;
                                        plVar12 = (longlong *)
                                                  FUN_23e91bfe0(param_1,plVar1,DAT_23eedcb28);
                                        if (plVar12 != (longlong *)0x0) {
                                          iVar6 = FUN_23a35f020(plVar12);
                                          *plVar12 = *plVar12 + -1;
                                          if (*plVar12 == 0) {
                                            FUN_23a334bc0(plVar12);
                                          }
                                          if (iVar6 != -1) {
                                            if (iVar6 == 0) goto LAB_23e88b333;
                                            FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                                            pcVar15 = _Py_TrueStruct_exref;
                                            *(longlong *)_Py_TrueStruct_exref =
                                                 *(longlong *)_Py_TrueStruct_exref + 1;
                                            *plVar8 = *plVar8 + -1;
                                            if (*plVar8 == 0) {
                                              (**(code **)(plVar8[1] + 0x30))(plVar8);
                                            }
                                            goto LAB_23e88accd;
                                          }
                                        }
                                        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                        local_68 = *(longlong **)(param_1 + 0x70);
                                        uVar16 = 0xc1;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        goto LAB_23e88b3cf;
                                      }
                                    }
                                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                    local_68 = *(longlong **)(param_1 + 0x70);
                                    uVar16 = 0xbd;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    goto LAB_23e88b3cf;
                                  }
                                }
                              }
                            }
                          }
                        }
                        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                        local_68 = *(longlong **)(param_1 + 0x70);
                        uVar16 = 0xbe;
                      }
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar11 = *plVar11 + -1;
                      if (*plVar11 == 0) {
                        FUN_23a334bc0(plVar11);
                      }
                    }
                  }
                }
                goto LAB_23e88b3cf;
              }
LAB_23e88b123:
              iVar6 = FUN_23e97a530(plVar8,DAT_23eedcab0);
              if (iVar6 == -1) {
LAB_23e88bfbe:
                local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                local_68 = *(longlong **)(param_1 + 0x70);
                uVar16 = 0xb3;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e88b3cf;
              }
              if (iVar6 == 1) {
                iVar6 = FUN_23e97a530(plVar9,DAT_23eedcab8);
                if (iVar6 == -1) goto LAB_23e88bfbe;
                if (iVar6 != 1) goto LAB_23e88b144;
                cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eedca18,DAT_23eedcac0);
                if (cVar5 == '\0') {
                  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_68 = *(longlong **)(param_1 + 0x70);
                  uVar16 = 0xb4;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e88b3cf;
                }
                lVar10 = *(longlong *)(DAT_23eedc7f0 + 0x20);
                if (*(char *)(lVar10 + 10) == '\0') {
                  plVar12 = (longlong *)FUN_23a37a020(DAT_23eedc7f0,DAT_23eedcac8);
                  if (plVar12 == (longlong *)0x0) goto LAB_23e88c1b9;
                  lVar10 = *plVar12;
LAB_23e88c1b0:
                  if (lVar10 == 0) goto LAB_23e88c1b9;
                }
                else {
                  iVar6 = *(int *)(lVar10 + 0xc);
                  if (*(int *)(lVar10 + 0xc) == 0) {
                    *(int *)(lVar10 + 0xc) = DAT_23ec1555c;
                    iVar6 = DAT_23ec1555c;
                    DAT_23ec1555c = DAT_23ec1555c + 1;
                  }
                  if (DAT_23ec15548 != iVar6) {
                    DAT_23ec15548 = iVar6;
                    DAT_23eede660 =
                         FUN_23e8cbd60(lVar10,DAT_23eedcac8,*(undefined8 *)(DAT_23eedcac8 + 0x18));
                  }
                  if (-1 < DAT_23eede660) {
                    lVar2 = lVar10 + 0x20 + (1L << (*(byte *)(lVar10 + 9) & 0x3f));
                    if (*(longlong *)(lVar2 + 8 + DAT_23eede660 * 0x10) != 0) goto LAB_23e88beb4;
                    DAT_23eede660 =
                         FUN_23e8cbd60(lVar10,DAT_23eedcac8,*(undefined8 *)(DAT_23eedcac8 + 0x18));
                    if (-1 < DAT_23eede660) {
                      lVar10 = *(longlong *)(lVar2 + 8 + DAT_23eede660 * 0x10);
                      goto LAB_23e88c1b0;
                    }
                  }
LAB_23e88c1b9:
                  plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eedcac8);
                  if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
                    uVar16 = 0xb5;
                    FUN_23e915740(param_1,local_78,DAT_23eedcac8);
                    goto LAB_23e88b3cf;
                  }
                }
LAB_23e88beb4:
                cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eedca20);
                if (cVar5 == '\0') {
                  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                  local_68 = *(longlong **)(param_1 + 0x70);
                  uVar16 = 0xb5;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                }
                else {
                  cVar5 = FUN_23e8d9ac0(plVar1,DAT_23eedcaa0,DAT_23eedcad0);
                  if (cVar5 == '\0') {
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar16 = 0xb6;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                  else {
                    uVar7 = FUN_23a3a0d40(DAT_23ed6cf28);
                    *(undefined4 *)(plVar3 + 5) = 0xb7;
                    plVar12 = (longlong *)FUN_23e94bb80(param_1,uVar7);
                    if (plVar12 != (longlong *)0x0) goto LAB_23e88ba73;
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar16 = 0xb7;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                }
                goto LAB_23e88b3cf;
              }
LAB_23e88b144:
              uVar7 = FUN_23a3a0d40(DAT_23ed6cf28);
              plVar11 = DAT_23eedcae0;
              lVar10 = *(longlong *)(param_1 + 0x10);
              plVar12 = *(longlong **)(lVar10 + 0xe30);
              if (plVar12 == (longlong *)0x0) {
                plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,4);
              }
              else {
                lVar2 = plVar12[3];
                *(int *)(lVar10 + 0xec4) = *(int *)(lVar10 + 0xec4) + -1;
                *(longlong *)(lVar10 + 0xe30) = lVar2;
                *plVar12 = 1;
              }
              pcVar15 = _PyRuntime_exref;
              plVar12[6] = 0;
              *(undefined1 (*) [16])(plVar12 + 4) = (undefined1  [16])0x0;
              lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar15 + 0x1f8) + 0x10) + 0x2e8);
              lVar2 = plVar12[-1];
              puVar4 = *(undefined8 **)(lVar10 + 8);
              *puVar4 = plVar12 + -2;
              plVar12[-2] = lVar10;
              plVar12[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
              *(longlong **)(lVar10 + 8) = plVar12 + -2;
              plVar14 = DAT_23ed6a4c0;
              *plVar11 = *plVar11 + 1;
              plVar12[3] = (longlong)plVar11;
              uVar13 = DAT_23ed6cd28;
              if (plVar14 == (longlong *)0x0) {
                plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                if (plVar14 == (longlong *)0x0) goto LAB_23e88c056;
                *plVar14 = *plVar14 + 1;
                DAT_23ed6a4c0 = plVar14;
              }
              uStack_80 = uVar13;
              local_88 = plVar8;
              lVar10 = FUN_23e94ed00(param_1,plVar14,&local_88);
              if (lVar10 != 0) {
                plVar12[4] = lVar10;
                plVar11 = DAT_23eedca70;
                *DAT_23eedca70 = *DAT_23eedca70 + 1;
                plVar12[5] = (longlong)plVar11;
                uVar13 = DAT_23ed6cd28;
                if (DAT_23ed6a4c0 == (longlong *)0x0) {
                  plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                  if (plVar11 == (longlong *)0x0) goto LAB_23e88c056;
                  *plVar11 = *plVar11 + 1;
                  DAT_23ed6a4c0 = plVar11;
                }
                uStack_80 = uVar13;
                local_88 = plVar9;
                lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_88);
                if (lVar10 != 0) {
                  plVar12[6] = lVar10;
                  plVar11 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  if (plVar11 == (longlong *)0x0) {
LAB_23e88c028:
                    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                    local_68 = *(longlong **)(param_1 + 0x70);
                    uVar16 = 0xb9;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e88b3cf;
                  }
                  *(undefined4 *)(plVar3 + 5) = 0xb9;
                  plVar12 = (longlong *)FUN_23e914090(param_1,uVar7,plVar11);
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  if (plVar12 == (longlong *)0x0) goto LAB_23e88c028;
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  uVar7 = FUN_23a3a0d40(DAT_23ed6cf28);
                  *(undefined4 *)(plVar3 + 5) = 0xba;
                  plVar12 = (longlong *)FUN_23e94bb80(param_1,uVar7,DAT_23eedcae8);
                  if (plVar12 == (longlong *)0x0) goto LAB_23e88c069;
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
LAB_23e88b333:
                  lVar10 = *(longlong *)_Py_FalseStruct_exref;
                  goto LAB_23e88ac5e;
                }
              }
              local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              local_68 = *(longlong **)(param_1 + 0x70);
              uVar16 = 0xb9;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *plVar12 = *plVar12 + -1;
              lVar10 = *plVar12;
            }
            if (lVar10 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            goto LAB_23e88b3cf;
          }
        }
        plVar11 = local_68;
        uVar7 = local_78._0_8_;
        uVar13 = local_78._8_8_;
        local_68 = (longlong *)0x0;
        local_78 = (undefined1  [16])0x0;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        local_68 = (longlong *)0x0;
        local_78 = (undefined1  [16])0x0;
        if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
      }
      uVar16 = 0xab;
      plVar9 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      local_78._8_8_ = uVar13;
      local_78._0_8_ = uVar7;
      local_68 = plVar11;
      goto LAB_23e88b3cf;
    }
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68 = *(longlong **)(param_1 + 0x70);
    plVar8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar17 = 0xa6;
    uVar16 = 0xa6;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar9 = (longlong *)0x0;
    if (local_68 == (longlong *)0x0) {
      local_68 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      goto LAB_23e88ad70;
    }
  }
  plVar12 = local_68;
  plVar11 = DAT_23ed6a4f8;
  if ((longlong *)local_68[3] != plVar3) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar14 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar14;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar15 = _PyRuntime_exref;
    plVar11[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar10 = *(longlong *)(pcVar15 + 0x1f8);
    *(undefined4 *)((longlong)plVar11 + 0x24) = uVar17;
    *(undefined4 *)(plVar11 + 4) = 0xffffffff;
    lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
    lVar2 = plVar11[-1];
    puVar4 = *(undefined8 **)(lVar10 + 8);
    *puVar4 = plVar11 + -2;
    plVar11[-2] = lVar10;
    plVar11[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar10 + 8) = plVar11 + -2;
    plVar11[2] = (longlong)plVar12;
    *plVar12 = *plVar12 + 1;
    plVar12 = plVar11;
    if ((local_68 != (longlong *)0x0) && (*local_68 = *local_68 + -1, *local_68 == 0)) {
      (**(code **)(local_68[1] + 0x30))();
    }
  }
LAB_23e88b491:
  local_68 = plVar12;
  FUN_23e8bba40(plVar3,&DAT_23ec5e2be,plVar1,plVar8,plVar9);
  if (DAT_23eede670 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    DAT_23eede670 = (longlong *)0x0;
  }
  lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar10 + 0x28);
  plVar12 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar12 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  plVar12 = local_68;
  plVar3[0xf] = 0;
  uVar7 = local_78._0_8_;
  uVar13 = local_78._8_8_;
  local_78 = (undefined1  [16])0x0;
  local_68 = (longlong *)0x0;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  *plVar1 = *plVar1 + -1;
  local_68 = plVar12;
  local_78._0_8_ = uVar7;
  local_78._8_8_ = uVar13;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,local_78._0_8_,local_78._8_8_,local_68);
  return (code *)0x0;
}
