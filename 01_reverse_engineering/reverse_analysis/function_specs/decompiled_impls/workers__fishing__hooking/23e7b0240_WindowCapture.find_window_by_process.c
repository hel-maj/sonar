/* ===== 23e7b0240 workers.fishing.hooking:142 ===== */
/* ghidra_name=FUN_23e7b0240 entry=23e7b0240 size=8120 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e7b0240(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  code *pcVar2;
  longlong *plVar3;
  longlong *plVar4;
  code *pcVar5;
  char cVar6;
  int iVar7;
  longlong *plVar8;
  longlong lVar9;
  code *pcVar10;
  longlong lVar11;
  longlong *plVar12;
  code *pcVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  longlong *plVar16;
  code *pcVar17;
  undefined8 *puVar18;
  code *pcVar19;
  code **ppcVar20;
  undefined4 uVar21;
  code *pcVar22;
  code *local_c0;
  code *local_a8;
  longlong *plStack_a0;
  undefined1 local_98 [16];
  code *local_88 [2];
  code *local_78;
  longlong *plStack_70;
  code *local_68;
  
  plVar8 = _DAT_23eedab00;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eedab00 == (longlong *)0x0) {
LAB_23e7b0285:
    _DAT_23eedab00 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedaaf8,DAT_23eedab78,0x10);
  }
  else {
    lVar9 = *_DAT_23eedab00;
    if (1 < lVar9) {
      *_DAT_23eedab00 = lVar9 + -1;
      goto LAB_23e7b0285;
    }
    if (_DAT_23eedab00[2] != 0) {
      *_DAT_23eedab00 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e7b0285;
    }
  }
  plVar4 = _DAT_23eedab00;
  lVar9 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23eedab00 + 9;
  lVar11 = *(longlong *)(lVar9 + 8);
  _DAT_23eedab00[0xf] = lVar11;
  *(longlong **)(lVar9 + 8) = plVar8;
  if ((lVar11 != 0) &&
     (((*(char *)(lVar11 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar11 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar11 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar11 + 0x38))) && (plVar4[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar11 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  uVar14 = _DAT_23eed7af0;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar14);
  if (plVar8 != (longlong *)0x0) {
    iVar7 = FUN_23e913250(plVar8,_DAT_23eed7b50);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (iVar7 != -1) {
      if (iVar7 != 1) {
        lVar9 = FUN_23e8df050();
        if (lVar9 != 0) {
          pcVar10 = (code *)FUN_23e8bc2f0(lVar9,_DAT_23eed7b58);
          if (pcVar10 == (code *)0x0) goto LAB_23e7b0494;
          ppcVar20 = *(code ***)(_DAT_23eed7948 + 0x20);
          if (*(char *)((longlong)ppcVar20 + 10) != '\0') {
            iVar7 = *(int *)((longlong)ppcVar20 + 0xc);
            if (*(int *)((longlong)ppcVar20 + 0xc) == 0) {
              *(int *)((longlong)ppcVar20 + 0xc) = _DAT_23ec153f4;
              iVar7 = _DAT_23ec153f4;
              _DAT_23ec153f4 = _DAT_23ec153f4 + 1;
            }
            if (_DAT_23ec153e4 != iVar7) {
              _DAT_23ec153e4 = iVar7;
              _DAT_23eedaae8 =
                   FUN_23e8cbd60(ppcVar20,_DAT_23eed7b80,*(undefined8 *)(_DAT_23eed7b80 + 0x18));
            }
            if (_DAT_23eedaae8 < 0) goto LAB_23e7b16c0;
            pcVar17 = (code *)((longlong)ppcVar20 +
                              (1L << (*(byte *)((longlong)ppcVar20 + 9) & 0x3f)) + 0x20);
            pcVar19 = *(code **)(pcVar17 + _DAT_23eedaae8 * 0x10 + 8);
            if (pcVar19 == (code *)0x0) goto LAB_23e7b1c7e;
            goto LAB_23e7b03f1;
          }
          puVar18 = (undefined8 *)FUN_23a37a020(_DAT_23eed7948,_DAT_23eed7b80);
          if (puVar18 == (undefined8 *)0x0) goto LAB_23e7b16c0;
          pcVar19 = (code *)*puVar18;
          goto LAB_23e7b16b4;
        }
        FUN_23e915740(param_1,&local_78,_DAT_23eed7aa0);
        local_c0._0_4_ = 0x96;
        pcVar10 = _Py_NoneStruct_exref;
        pcVar19 = local_68;
        pcVar22 = _PyRuntime_exref;
        pcVar17 = local_78;
        plVar8 = plStack_70;
        goto LAB_23e7b050d;
      }
      lVar9 = FUN_23e8df050();
      if (lVar9 == 0) {
        FUN_23e915740(param_1,&local_78,_DAT_23eed7aa0);
        local_c0._0_4_ = 0x92;
        pcVar10 = _Py_NoneStruct_exref;
        pcVar19 = local_68;
        pcVar22 = _PyRuntime_exref;
        pcVar17 = local_78;
        plVar8 = plStack_70;
        goto LAB_23e7b050d;
      }
      plVar12 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eed7b58);
      if (plVar12 == (longlong *)0x0) goto LAB_23e7b13b0;
      lVar9 = *(longlong *)(_DAT_23eed7948 + 0x20);
      if (*(char *)(lVar9 + 10) == '\0') {
        puVar18 = (undefined8 *)FUN_23a37a020(_DAT_23eed7948,_DAT_23eed7b60);
        if (puVar18 == (undefined8 *)0x0) goto LAB_23e7b1ab0;
        pcVar10 = (code *)*puVar18;
LAB_23e7b1a98:
        if (pcVar10 == (code *)0x0) goto LAB_23e7b1ab0;
LAB_23e7b0c52:
        lVar11 = FUN_23e8df050();
        lVar9 = _DAT_23eed7aa0;
        if (lVar11 == 0) goto LAB_23e7b1ae3;
        plVar8 = (longlong *)FUN_23e8bc2f0(lVar11,_DAT_23eed7b68);
        if (plVar8 != (longlong *)0x0) {
          *(undefined4 *)(plVar4 + 5) = 0x92;
          local_78 = pcVar10;
          plStack_70 = plVar8;
          plVar16 = (longlong *)FUN_23e94ed00(param_1,plVar12,&local_78);
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          if (plVar16 != (longlong *)0x0) {
            cVar6 = FUN_23e8d9ac0(plVar1,_DAT_23eed7b18,plVar16);
            *plVar16 = *plVar16 + -1;
            if (*plVar16 == 0) {
              (**(code **)(plVar16[1] + 0x30))(plVar16);
            }
            if (cVar6 != '\0') {
              lVar9 = FUN_23e8df050();
              if (lVar9 == 0) {
                FUN_23e915740(param_1,&local_78,_DAT_23eed7aa0);
                local_c0._0_4_ = 0x93;
                pcVar10 = _Py_NoneStruct_exref;
                pcVar19 = local_68;
                pcVar22 = _PyRuntime_exref;
                pcVar17 = local_78;
                plVar8 = plStack_70;
                goto LAB_23e7b050d;
              }
              plVar12 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eed7b58);
              if (plVar12 == (longlong *)0x0) {
LAB_23e7b1cd4:
                pcVar17 = *(code **)(param_1 + 0x60);
                pcVar19 = *(code **)(param_1 + 0x70);
                local_c0._0_4_ = 0x93;
                *(undefined8 *)(param_1 + 0x70) = 0;
                pcVar22 = _PyRuntime_exref;
                pcVar10 = _Py_NoneStruct_exref;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar8 = *(longlong **)(param_1 + 0x68);
                goto LAB_23e7b050d;
              }
              lVar9 = *(longlong *)(_DAT_23eed7948 + 0x20);
              if (*(char *)(lVar9 + 10) == '\0') {
                puVar18 = (undefined8 *)FUN_23a37a020(_DAT_23eed7948,_DAT_23eed7b70);
                if (puVar18 == (undefined8 *)0x0) goto LAB_23e7b1e57;
                pcVar10 = (code *)*puVar18;
LAB_23e7b1e4e:
                if (pcVar10 == (code *)0x0) goto LAB_23e7b1e57;
LAB_23e7b0d93:
                lVar11 = FUN_23e8df050();
                lVar9 = _DAT_23eed7aa0;
                if (lVar11 == 0) goto LAB_23e7b1e85;
                plVar8 = (longlong *)FUN_23e8bc2f0(lVar11,_DAT_23eed7b68);
                if (plVar8 != (longlong *)0x0) {
                  *(undefined4 *)(plVar4 + 5) = 0x93;
                  local_78 = pcVar10;
                  plStack_70 = plVar8;
                  plVar16 = (longlong *)FUN_23e94ed00(param_1,plVar12,&local_78);
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  *plVar8 = *plVar8 + -1;
                  if (*plVar8 == 0) {
                    (**(code **)(plVar8[1] + 0x30))(plVar8);
                  }
                  if (plVar16 != (longlong *)0x0) {
                    cVar6 = FUN_23e8d9ac0(plVar1,_DAT_23eed7b20,plVar16);
                    *plVar16 = *plVar16 + -1;
                    if (*plVar16 == 0) {
                      (**(code **)(plVar16[1] + 0x30))(plVar16);
                    }
                    if (cVar6 != '\0') {
                      uVar14 = FUN_23a3a0d40(DAT_23ed6cf28);
                      *(undefined4 *)(plVar4 + 5) = 0x94;
                      plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar14,_DAT_23eed7b78);
                      pcVar10 = _Py_NoneStruct_exref;
                      if (plVar8 != (longlong *)0x0) {
                        *plVar8 = *plVar8 + -1;
                        if (*plVar8 != 0) goto LAB_23e7b0e78;
                        FUN_23a334bc0(plVar8);
                        goto LAB_23e7b0e78;
                      }
                      pcVar17 = *(code **)(param_1 + 0x60);
                      pcVar19 = *(code **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      pcVar22 = _PyRuntime_exref;
                      local_c0._0_4_ = 0x94;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      plVar8 = *(longlong **)(param_1 + 0x68);
                      goto LAB_23e7b050d;
                    }
                  }
                  goto LAB_23e7b1cd4;
                }
                pcVar17 = *(code **)(param_1 + 0x60);
                plVar8 = *(longlong **)(param_1 + 0x68);
                pcVar19 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                  local_c0._0_4_ = 0x93;
                  pcVar10 = _Py_NoneStruct_exref;
                  pcVar22 = _PyRuntime_exref;
                  goto LAB_23e7b050d;
                }
              }
              else {
                iVar7 = *(int *)(lVar9 + 0xc);
                if (*(int *)(lVar9 + 0xc) == 0) {
                  *(int *)(lVar9 + 0xc) = _DAT_23ec153f4;
                  iVar7 = _DAT_23ec153f4;
                  _DAT_23ec153f4 = _DAT_23ec153f4 + 1;
                }
                if (_DAT_23ec153e0 != iVar7) {
                  _DAT_23ec153e0 = iVar7;
                  _DAT_23eedaae0 =
                       FUN_23e8cbd60(lVar9,_DAT_23eed7b70,*(undefined8 *)(_DAT_23eed7b70 + 0x18));
                }
                if (-1 < _DAT_23eedaae0) {
                  lVar11 = lVar9 + 0x20 + (1L << (*(byte *)(lVar9 + 9) & 0x3f));
                  pcVar10 = *(code **)(lVar11 + 8 + _DAT_23eedaae0 * 0x10);
                  if (pcVar10 != (code *)0x0) goto LAB_23e7b0d93;
                  _DAT_23eedaae0 =
                       FUN_23e8cbd60(lVar9,_DAT_23eed7b70,*(undefined8 *)(_DAT_23eed7b70 + 0x18));
                  if (-1 < _DAT_23eedaae0) {
                    pcVar10 = *(code **)(lVar11 + 8 + _DAT_23eedaae0 * 0x10);
                    goto LAB_23e7b1e4e;
                  }
                }
LAB_23e7b1e57:
                puVar18 = (undefined8 *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eed7b70);
                lVar9 = _DAT_23eed7b70;
                if ((puVar18 != (undefined8 *)0x0) &&
                   (pcVar10 = (code *)*puVar18, pcVar10 != (code *)0x0)) goto LAB_23e7b0d93;
LAB_23e7b1e85:
                FUN_23e915740(param_1,&local_78,lVar9);
                pcVar19 = local_68;
                plVar8 = plStack_70;
                pcVar17 = local_78;
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  FUN_23a334bc0(plVar12);
                  local_c0._0_4_ = 0x93;
                  pcVar10 = _Py_NoneStruct_exref;
                  pcVar22 = _PyRuntime_exref;
                  goto LAB_23e7b050d;
                }
              }
              local_c0._0_4_ = 0x93;
              pcVar10 = _Py_NoneStruct_exref;
              pcVar22 = _PyRuntime_exref;
              goto LAB_23e7b050d;
            }
          }
LAB_23e7b13b0:
          pcVar17 = *(code **)(param_1 + 0x60);
          pcVar19 = *(code **)(param_1 + 0x70);
          local_c0._0_4_ = 0x92;
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcVar22 = _PyRuntime_exref;
          pcVar10 = _Py_NoneStruct_exref;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar8 = *(longlong **)(param_1 + 0x68);
          goto LAB_23e7b050d;
        }
        pcVar17 = *(code **)(param_1 + 0x60);
        plVar8 = *(longlong **)(param_1 + 0x68);
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar12 = *plVar12 + -1;
        lVar9 = *plVar12;
      }
      else {
        iVar7 = *(int *)(lVar9 + 0xc);
        if (*(int *)(lVar9 + 0xc) == 0) {
          *(int *)(lVar9 + 0xc) = _DAT_23ec153f4;
          iVar7 = _DAT_23ec153f4;
          _DAT_23ec153f4 = _DAT_23ec153f4 + 1;
        }
        if (_DAT_23ec153dc != iVar7) {
          _DAT_23ec153dc = iVar7;
          _DAT_23eedaad8 =
               FUN_23e8cbd60(lVar9,_DAT_23eed7b60,*(undefined8 *)(_DAT_23eed7b60 + 0x18));
        }
        if (-1 < _DAT_23eedaad8) {
          lVar11 = lVar9 + 0x20 + (1L << (*(byte *)(lVar9 + 9) & 0x3f));
          pcVar10 = *(code **)(lVar11 + 8 + _DAT_23eedaad8 * 0x10);
          if (pcVar10 != (code *)0x0) goto LAB_23e7b0c52;
          _DAT_23eedaad8 =
               FUN_23e8cbd60(lVar9,_DAT_23eed7b60,*(undefined8 *)(_DAT_23eed7b60 + 0x18));
          if (-1 < _DAT_23eedaad8) {
            pcVar10 = *(code **)(lVar11 + 8 + _DAT_23eedaad8 * 0x10);
            goto LAB_23e7b1a98;
          }
        }
LAB_23e7b1ab0:
        puVar18 = (undefined8 *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eed7b60);
        lVar9 = _DAT_23eed7b60;
        if ((puVar18 != (undefined8 *)0x0) && (pcVar10 = (code *)*puVar18, pcVar10 != (code *)0x0))
        goto LAB_23e7b0c52;
LAB_23e7b1ae3:
        FUN_23e915740(param_1,&local_78,lVar9);
        *plVar12 = *plVar12 + -1;
        lVar9 = *plVar12;
        pcVar19 = local_68;
        pcVar17 = local_78;
        plVar8 = plStack_70;
      }
      if (lVar9 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
        local_c0._0_4_ = 0x92;
        pcVar10 = _Py_NoneStruct_exref;
        pcVar22 = _PyRuntime_exref;
      }
      else {
        local_c0._0_4_ = 0x92;
        pcVar10 = _Py_NoneStruct_exref;
        pcVar22 = _PyRuntime_exref;
      }
      goto LAB_23e7b050d;
    }
  }
  pcVar19 = *(code **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  pcVar22 = _PyRuntime_exref;
  pcVar10 = _Py_NoneStruct_exref;
  local_c0._0_4_ = 0x91;
  pcVar17 = *(code **)(param_1 + 0x60);
  plVar8 = *(longlong **)(param_1 + 0x68);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e7b050d:
  do {
    ppcVar20 = *(code ***)(param_1 + 0x138);
    local_98._8_8_ = plVar8;
    local_98._0_8_ = pcVar17;
    if (ppcVar20 != (code **)0x0) {
      *ppcVar20 = *ppcVar20 + 1;
    }
    pcVar17 = DAT_23ed6a4f8;
    local_88[0] = pcVar19;
    if (pcVar19 == (code *)0x0) {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar19 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar19;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong *)(pcVar17 + 0x10) = 0;
      *(longlong **)(pcVar17 + 0x18) = plVar4;
      *plVar4 = *plVar4 + 1;
      lVar9 = *(longlong *)(pcVar22 + 0x1f8);
      *(undefined4 *)(pcVar17 + 0x24) = local_c0._0_4_;
      lVar9 = *(longlong *)(lVar9 + 0x10);
      *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
      lVar9 = *(longlong *)(lVar9 + 0x2e8);
      lVar11 = *(longlong *)(pcVar17 + -8);
      puVar18 = *(undefined8 **)(lVar9 + 8);
      *puVar18 = pcVar17 + -0x10;
      *(longlong *)(pcVar17 + -0x10) = lVar9;
      *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar11 & 3) | (ulonglong)puVar18;
      *(code **)(lVar9 + 8) = pcVar17 + -0x10;
      if ((local_88[0] != (code *)0x0) &&
         (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1, *(longlong *)local_88[0] == 0))
      {
        (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))(local_88[0]);
      }
    }
    else {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar13 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar13;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong **)(pcVar17 + 0x18) = plVar4;
      *plVar4 = *plVar4 + 1;
      lVar9 = *(longlong *)(pcVar22 + 0x1f8);
      *(undefined4 *)(pcVar17 + 0x24) = local_c0._0_4_;
      lVar9 = *(longlong *)(lVar9 + 0x10);
      *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
      lVar9 = *(longlong *)(lVar9 + 0x2e8);
      lVar11 = *(longlong *)(pcVar17 + -8);
      puVar18 = *(undefined8 **)(lVar9 + 8);
      *puVar18 = pcVar17 + -0x10;
      *(longlong *)(pcVar17 + -0x10) = lVar9;
      *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar11 & 3) | (ulonglong)puVar18;
      *(code **)(lVar9 + 8) = pcVar17 + -0x10;
      *(code **)(pcVar17 + 0x10) = pcVar19;
      *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
      if ((local_88[0] != (code *)0x0) &&
         (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1, *(longlong *)local_88[0] == 0))
      {
        (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))();
      }
    }
    local_88[0] = pcVar17;
    if (((code *)local_98._0_8_ != pcVar10) && ((code *)local_98._0_8_ != (code *)0x0)) {
      FUN_23e91b1b0(param_1,local_98,local_98 + 8,local_88);
    }
    plVar8 = *(longlong **)(local_98._8_8_ + 0x28);
    if (local_88[0] == pcVar10) {
      pcVar19 = (code *)0x0;
    }
    else {
      pcVar19 = local_88[0];
      if (local_88[0] != (code *)0x0) {
        *(longlong *)local_88[0] = *(longlong *)local_88[0] + 1;
      }
    }
    *(code **)(local_98._8_8_ + 0x28) = pcVar19;
    if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
      (**(code **)(plVar8[1] + 0x30))();
    }
    plVar8 = *(longlong **)(param_1 + 0x138);
    *(undefined8 *)(param_1 + 0x138) = local_98._8_8_;
    if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
      (**(code **)(plVar8[1] + 0x30))();
    }
    *(longlong *)local_98._0_8_ = *(longlong *)local_98._0_8_ + -1;
    if (*(longlong *)local_98._0_8_ == 0) {
      (**(code **)(*(longlong *)(local_98._0_8_ + 8) + 0x30))();
    }
    if ((local_88[0] != (code *)0x0) &&
       (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1, *(longlong *)local_88[0] == 0)) {
      (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))();
    }
    pcVar17 = *(code **)(param_1 + 0x138);
    local_88[0] = (code *)0x0;
    local_98 = (undefined1  [16])0x0;
    pcVar19 = *(code **)PyExc_Exception_exref;
    pcVar13 = *(code **)(pcVar17 + 8);
    if ((*(uint *)(*(longlong *)(pcVar19 + 8) + 0xa8) & 0x4000000) != 0) {
      lVar9 = *(longlong *)(pcVar19 + 0x10);
      if (0 < lVar9) {
        lVar11 = 0;
        do {
          if ((-1 < *(int *)(*(longlong *)(*(longlong *)(pcVar19 + lVar11 * 8 + 0x18) + 8) + 0xa8))
             || ((*(byte *)(*(longlong *)(pcVar19 + lVar11 * 8 + 0x18) + 0xab) & 0x40) == 0)) {
            plVar8 = *(longlong **)PyExc_TypeError_exref;
            uVar14 = PyUnicode_FromString
                               (
                               "catching classes that do not inherit from BaseException is not allowed"
                               );
            plVar12 = *(longlong **)(param_1 + 0x60);
            plVar16 = *(longlong **)(param_1 + 0x68);
            plVar3 = *(longlong **)(param_1 + 0x70);
            *(longlong **)(param_1 + 0x60) = plVar8;
            *plVar8 = *plVar8 + 1;
            *(undefined8 *)(param_1 + 0x68) = uVar14;
            *(undefined8 *)(param_1 + 0x70) = 0;
            if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
              (**(code **)(plVar12[1] + 0x30))();
            }
            if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
              (**(code **)(plVar16[1] + 0x30))(plVar16);
            }
            if ((plVar3 == (longlong *)0x0) || (*plVar3 = *plVar3 + -1, *plVar3 != 0))
            goto LAB_23e7b08cf;
            (**(code **)(plVar3[1] + 0x30))(plVar3);
            pcVar17 = *(code **)(param_1 + 0x138);
            goto LAB_23e7b08d6;
          }
          lVar11 = lVar11 + 1;
        } while (lVar9 != lVar11);
        lVar11 = 0;
        while (iVar7 = FUN_23a35ebd0(param_1,pcVar13,*(undefined8 *)(pcVar19 + lVar11 * 8 + 0x18)),
              iVar7 == 0) {
          lVar11 = lVar11 + 1;
          if (lVar9 == lVar11) {
            pcVar17 = *(code **)(param_1 + 0x138);
            goto LAB_23e7b0742;
          }
        }
LAB_23e7b08cf:
        pcVar17 = *(code **)(param_1 + 0x138);
        goto LAB_23e7b08d6;
      }
LAB_23e7b0742:
      if ((pcVar17 != pcVar10) && (pcVar17 != (code *)0x0)) {
        plVar8 = *(longlong **)(pcVar17 + 8);
        pcVar10 = *(code **)(pcVar17 + 0x28);
        *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
        *plVar8 = *plVar8 + 1;
        local_c0 = pcVar17;
        if (pcVar10 == (code *)0x0) {
          *(code ***)(param_1 + 0x138) = ppcVar20;
          *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
          if (*(longlong *)pcVar17 == 0) {
            iVar7 = 0;
            goto LAB_23e7b1a28;
          }
LAB_23e7b127a:
          iVar7 = (int)plVar4[5];
          goto LAB_23e7b1283;
        }
        *(longlong *)pcVar10 = *(longlong *)pcVar10 + 1;
        if (*(longlong **)(pcVar10 + 0x18) == plVar4) {
          *(undefined4 *)(plVar4 + 5) = *(undefined4 *)(pcVar10 + 0x24);
        }
        *(code ***)(param_1 + 0x138) = ppcVar20;
        *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
        if (*(longlong *)pcVar17 == 0) {
          (*(code *)plVar8[6])(pcVar17);
          iVar7 = 0;
          goto LAB_23e7b14dd;
        }
        pcVar19 = pcVar10;
        if (plVar4 == *(longlong **)(pcVar10 + 0x18)) goto LAB_23e7b1310;
LAB_23e7b14f4:
        uVar21 = (undefined4)plVar4[5];
LAB_23e7b14f8:
        pcVar19 = DAT_23ed6a4f8;
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar19 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          pcVar17 = *(code **)DAT_23ed6a4f8;
          *(longlong *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar17;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        }
        *(longlong **)(pcVar19 + 0x18) = plVar4;
        *plVar4 = *plVar4 + 1;
        lVar9 = *(longlong *)(pcVar22 + 0x1f8);
        *(undefined4 *)(pcVar19 + 0x20) = 0xffffffff;
        lVar9 = *(longlong *)(lVar9 + 0x10);
        *(undefined4 *)(pcVar19 + 0x24) = uVar21;
        lVar9 = *(longlong *)(lVar9 + 0x2e8);
        lVar11 = *(longlong *)(pcVar19 + -8);
        puVar18 = *(undefined8 **)(lVar9 + 8);
        *puVar18 = pcVar19 + -0x10;
        *(longlong *)(pcVar19 + -0x10) = lVar9;
        *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar11 & 3) | (ulonglong)puVar18;
        lVar11 = *(longlong *)pcVar10;
        *(code **)(lVar9 + 8) = pcVar19 + -0x10;
        *(code **)(pcVar19 + 0x10) = pcVar10;
        if (lVar11 == 0) {
          (**(code **)(*(longlong *)(pcVar10 + 8) + 0x30))(pcVar10);
        }
        goto LAB_23e7b1310;
      }
      plVar8 = *(longlong **)PyExc_RuntimeError_exref;
      local_c0 = (code *)PyUnicode_FromString("No active exception to reraise");
      pcVar17 = *(code **)(param_1 + 0x138);
      *plVar8 = *plVar8 + 1;
      *(code ***)(param_1 + 0x138) = ppcVar20;
      iVar7 = 0x90;
      if ((pcVar17 != (code *)0x0) &&
         (*(longlong *)pcVar17 = *(longlong *)pcVar17 + -1, *(longlong *)pcVar17 == 0)) {
LAB_23e7b1a28:
        (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))(pcVar17);
        if (iVar7 == 0) goto LAB_23e7b127a;
      }
LAB_23e7b1283:
      pcVar19 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar19 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar10 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar10;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong *)(pcVar19 + 0x10) = 0;
      *(longlong **)(pcVar19 + 0x18) = plVar4;
      *plVar4 = *plVar4 + 1;
      lVar9 = *(longlong *)(pcVar22 + 0x1f8);
      *(undefined4 *)(pcVar19 + 0x20) = 0xffffffff;
      lVar9 = *(longlong *)(lVar9 + 0x10);
      *(int *)(pcVar19 + 0x24) = iVar7;
      lVar9 = *(longlong *)(lVar9 + 0x2e8);
      lVar11 = *(longlong *)(pcVar19 + -8);
      puVar18 = *(undefined8 **)(lVar9 + 8);
      *puVar18 = pcVar19 + -0x10;
      *(longlong *)(pcVar19 + -0x10) = lVar9;
      *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar11 & 3) | (ulonglong)puVar18;
      *(code **)(lVar9 + 8) = pcVar19 + -0x10;
LAB_23e7b1310:
      FUN_23e8bba40(plVar4,&DAT_23ec5dd15,plVar1,0);
      if (_DAT_23eedab00 == plVar4) {
        *plVar4 = *plVar4 + -1;
        if (*plVar4 == 0) {
          (**(code **)(plVar4[1] + 0x30))(plVar4);
        }
        _DAT_23eedab00 = (longlong *)0x0;
      }
      lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar4 = *(longlong **)(lVar9 + 0x28);
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
      plVar12 = (longlong *)plVar4[2];
      *(undefined4 *)(plVar4 + 8) = 0xffffffff;
      if (plVar12 != (longlong *)0x0) {
        plVar4[2] = 0;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))();
        }
      }
      *plVar4 = *plVar4 + -1;
      if (*plVar4 == 0) {
        (**(code **)(plVar4[1] + 0x30))(plVar4);
      }
      plVar4[0xf] = 0;
      *plVar1 = *plVar1 + -1;
      if (*plVar1 == 0) {
        (**(code **)(plVar1[1] + 0x30))(plVar1);
      }
      FUN_23a33aa70(param_1,plVar8,local_c0,pcVar19);
      return (code *)0x0;
    }
    if (((int)*(uint *)(*(longlong *)(pcVar19 + 8) + 0xa8) < 0) &&
       (((byte)pcVar19[0xab] & 0x40) != 0)) {
      pcVar2 = *(code **)(pcVar13 + 8);
      if ((*(uint *)(pcVar2 + 0xa8) & 0x40000000) == 0) {
        pcVar5 = pcVar13;
        if (((int)*(uint *)(pcVar2 + 0xa8) < 0) && (((byte)pcVar13[0xab] & 0x40) != 0))
        goto LAB_23e7b081e;
      }
      else {
        pcVar13 = pcVar2;
        pcVar5 = pcVar2;
        if (*(int *)(*(longlong *)(pcVar2 + 8) + 0xa8) < 0) {
LAB_23e7b081e:
          lVar9 = *(longlong *)(pcVar13 + 0x158);
          if (lVar9 != 0) {
            if (*(longlong *)(lVar9 + 0x10) < 1) goto LAB_23e7b0742;
            lVar11 = 0;
            while (pcVar19 != *(code **)(lVar9 + 0x18 + lVar11 * 8)) {
              lVar11 = lVar11 + 1;
              if (*(longlong *)(lVar9 + 0x10) == lVar11) goto LAB_23e7b0742;
            }
            goto LAB_23e7b08d6;
          }
          do {
            if (pcVar19 == pcVar13) goto LAB_23e7b08d6;
            pcVar13 = *(code **)(pcVar13 + 0x100);
            pcVar5 = PyBaseObject_Type_exref;
          } while (pcVar13 != (code *)0x0);
        }
      }
      if (pcVar19 != pcVar5) goto LAB_23e7b0742;
    }
    else {
      plVar8 = *(longlong **)PyExc_TypeError_exref;
      uVar14 = PyUnicode_FromString
                         ("catching classes that do not inherit from BaseException is not allowed");
      plVar12 = *(longlong **)(param_1 + 0x60);
      plVar16 = *(longlong **)(param_1 + 0x68);
      plVar3 = *(longlong **)(param_1 + 0x70);
      *(longlong **)(param_1 + 0x60) = plVar8;
      *plVar8 = *plVar8 + 1;
      *(undefined8 *)(param_1 + 0x68) = uVar14;
      *(undefined8 *)(param_1 + 0x70) = 0;
      if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
        (**(code **)(plVar12[1] + 0x30))();
      }
      if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
        (**(code **)(plVar16[1] + 0x30))(plVar16);
      }
      if ((plVar3 == (longlong *)0x0) || (*plVar3 = *plVar3 + -1, *plVar3 != 0)) goto LAB_23e7b08cf;
      (**(code **)(plVar3[1] + 0x30))(plVar3);
      pcVar17 = *(code **)(param_1 + 0x138);
    }
LAB_23e7b08d6:
    *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
    uVar14 = FUN_23a3a0d40(DAT_23ed6cf28);
    plVar8 = _DAT_23eed7bb8;
    lVar9 = *(longlong *)(param_1 + 0x10);
    plVar12 = *(longlong **)(lVar9 + 0xe20);
    if (plVar12 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      lVar11 = plVar12[3];
      *(int *)(lVar9 + 0xebc) = *(int *)(lVar9 + 0xebc) + -1;
      *(longlong *)(lVar9 + 0xe20) = lVar11;
      *plVar12 = 1;
    }
    lVar9 = *(longlong *)(pcVar22 + 0x1f8);
    plVar12[4] = 0;
    lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
    lVar11 = plVar12[-1];
    puVar18 = *(undefined8 **)(lVar9 + 8);
    *puVar18 = plVar12 + -2;
    plVar12[-2] = lVar9;
    plVar12[-1] = (ulonglong)((uint)lVar11 & 3) | (ulonglong)puVar18;
    *(longlong **)(lVar9 + 8) = plVar12 + -2;
    plVar16 = DAT_23ed6a4c0;
    *plVar8 = *plVar8 + 1;
    plVar12[3] = (longlong)plVar8;
    plVar8 = DAT_23ed6cd28;
    if (plVar16 != (longlong *)0x0) {
LAB_23e7b0992:
      plStack_a0 = plVar8;
      local_a8 = pcVar17;
      lVar9 = FUN_23e94ed00(param_1,plVar16,&local_a8);
      if (lVar9 == 0) {
        local_c0 = *(code **)(param_1 + 0x68);
        plVar8 = *(longlong **)(param_1 + 0x60);
        pcVar10 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
      }
      else {
        plVar12[4] = lVar9;
        plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        if (plVar8 != (longlong *)0x0) {
          *(undefined4 *)(plVar4 + 5) = 0xa5;
          plVar12 = (longlong *)FUN_23e914090(param_1,uVar14,plVar8);
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          if (plVar12 != (longlong *)0x0) {
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
            if (*(longlong *)pcVar17 == 0) {
              (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))(pcVar17);
            }
            plVar8 = *(longlong **)(param_1 + 0x138);
            *(code ***)(param_1 + 0x138) = ppcVar20;
            if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
              (**(code **)(plVar8[1] + 0x30))();
            }
            goto LAB_23e7b0a60;
          }
        }
        local_c0 = *(code **)(param_1 + 0x68);
        plVar8 = *(longlong **)(param_1 + 0x60);
        pcVar10 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
      }
      *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
      if (*(longlong *)pcVar17 == 0) {
        (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))(pcVar17);
      }
      plVar12 = *(longlong **)(param_1 + 0x138);
      *(code ***)(param_1 + 0x138) = ppcVar20;
      if (plVar12 == (longlong *)0x0) {
        if (pcVar10 != (code *)0x0) {
          plVar12 = *(longlong **)(pcVar10 + 0x18);
joined_r0x00023e7b148c:
          pcVar19 = pcVar10;
          if (plVar12 == plVar4) goto LAB_23e7b1310;
          uVar21 = 0xa5;
          goto LAB_23e7b14f8;
        }
      }
      else {
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))();
          if (pcVar10 != (code *)0x0) {
            iVar7 = 0xa5;
LAB_23e7b14dd:
            pcVar19 = pcVar10;
            if (plVar4 == *(longlong **)(pcVar10 + 0x18)) goto LAB_23e7b1310;
            uVar21 = 0xa5;
            if (iVar7 == 0) goto LAB_23e7b14f4;
            goto LAB_23e7b14f8;
          }
        }
        else if (pcVar10 != (code *)0x0) {
          plVar12 = *(longlong **)(pcVar10 + 0x18);
          goto joined_r0x00023e7b148c;
        }
      }
      iVar7 = 0xa5;
      goto LAB_23e7b1283;
    }
    plVar16 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
    if (plVar16 != (longlong *)0x0) {
      *plVar16 = *plVar16 + 1;
      DAT_23ed6a4c0 = plVar16;
      goto LAB_23e7b0992;
    }
    do {
      PyErr_PrintEx(0);
      Py_Exit(1);
LAB_23e7b1c7e:
      _DAT_23eedaae8 = FUN_23e8cbd60(ppcVar20,_DAT_23eed7b80,*(undefined8 *)(_DAT_23eed7b80 + 0x18))
      ;
      if (_DAT_23eedaae8 < 0) {
LAB_23e7b16c0:
        puVar18 = (undefined8 *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eed7b80);
        lVar9 = _DAT_23eed7b80;
        if ((puVar18 != (undefined8 *)0x0) && (pcVar19 = (code *)*puVar18, pcVar19 != (code *)0x0))
        goto LAB_23e7b03f1;
LAB_23e7b16f3:
        FUN_23e915740(param_1,&local_78,lVar9);
        *(longlong *)pcVar10 = *(longlong *)pcVar10 + -1;
        lVar9 = *(longlong *)pcVar10;
        pcVar19 = local_68;
        pcVar17 = local_78;
        plVar8 = plStack_70;
joined_r0x00023e7b17ad:
        if (lVar9 == 0) {
          (**(code **)(*(longlong *)(pcVar10 + 8) + 0x30))(pcVar10);
          local_c0._0_4_ = 0x96;
          pcVar10 = _Py_NoneStruct_exref;
          pcVar22 = _PyRuntime_exref;
        }
        else {
          local_c0._0_4_ = 0x96;
          pcVar10 = _Py_NoneStruct_exref;
          pcVar22 = _PyRuntime_exref;
        }
        goto LAB_23e7b050d;
      }
      pcVar19 = *(code **)(pcVar17 + _DAT_23eedaae8 * 0x10 + 8);
LAB_23e7b16b4:
      if (pcVar19 == (code *)0x0) goto LAB_23e7b16c0;
LAB_23e7b03f1:
      lVar11 = FUN_23e8df050();
      lVar9 = _DAT_23eed7aa0;
      if (lVar11 == 0) goto LAB_23e7b16f3;
      plVar8 = (longlong *)FUN_23e8bc2f0(lVar11,_DAT_23eed7b68);
      if (plVar8 == (longlong *)0x0) {
        pcVar17 = *(code **)(param_1 + 0x60);
        plVar8 = *(longlong **)(param_1 + 0x68);
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(longlong *)pcVar10 = *(longlong *)pcVar10 + -1;
        lVar9 = *(longlong *)pcVar10;
        goto joined_r0x00023e7b17ad;
      }
      *(undefined4 *)(plVar4 + 5) = 0x96;
      local_78 = pcVar19;
      plStack_70 = plVar8;
      plVar12 = (longlong *)FUN_23e94ed00(param_1,pcVar10,&local_78);
      *(longlong *)pcVar10 = *(longlong *)pcVar10 + -1;
      if (*(longlong *)pcVar10 == 0) {
        (**(code **)(*(longlong *)(pcVar10 + 8) + 0x30))(pcVar10);
      }
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      if (plVar12 == (longlong *)0x0) goto LAB_23e7b0494;
      cVar6 = FUN_23e8d9ac0(plVar1,_DAT_23eed7b18,plVar12);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      if (cVar6 == '\0') goto LAB_23e7b0494;
      lVar9 = FUN_23e8df050();
      if (lVar9 == 0) {
        FUN_23e915740(param_1,&local_78,_DAT_23eed7aa0);
        local_c0._0_4_ = 0x97;
        pcVar10 = _Py_NoneStruct_exref;
        pcVar19 = local_68;
        pcVar22 = _PyRuntime_exref;
        pcVar17 = local_78;
        plVar8 = plStack_70;
        goto LAB_23e7b050d;
      }
      plVar12 = (longlong *)FUN_23e8bc2f0(lVar9,_DAT_23eed7b58);
      if (plVar12 == (longlong *)0x0) goto LAB_23e7b1bbd;
      lVar9 = *(longlong *)(_DAT_23eed7948 + 0x20);
      if (*(char *)(lVar9 + 10) != '\0') {
        iVar7 = *(int *)(lVar9 + 0xc);
        if (*(int *)(lVar9 + 0xc) == 0) {
          *(int *)(lVar9 + 0xc) = _DAT_23ec153f4;
          iVar7 = _DAT_23ec153f4;
          _DAT_23ec153f4 = _DAT_23ec153f4 + 1;
        }
        if (_DAT_23ec153e8 != iVar7) {
          _DAT_23ec153e8 = iVar7;
          _DAT_23eedaaf0 =
               FUN_23e8cbd60(lVar9,_DAT_23eed7b88,*(undefined8 *)(_DAT_23eed7b88 + 0x18));
        }
        if (-1 < _DAT_23eedaaf0) {
          lVar11 = lVar9 + 0x20 + (1L << (*(byte *)(lVar9 + 9) & 0x3f));
          pcVar10 = *(code **)(lVar11 + 8 + _DAT_23eedaaf0 * 0x10);
          if (pcVar10 != (code *)0x0) goto LAB_23e7b18f6;
          _DAT_23eedaaf0 =
               FUN_23e8cbd60(lVar9,_DAT_23eed7b88,*(undefined8 *)(_DAT_23eed7b88 + 0x18));
          if (-1 < _DAT_23eedaaf0) {
            pcVar10 = *(code **)(lVar11 + 8 + _DAT_23eedaaf0 * 0x10);
            goto LAB_23e7b1d1a;
          }
        }
LAB_23e7b1d23:
        puVar18 = (undefined8 *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eed7b88);
        lVar9 = _DAT_23eed7b88;
        if ((puVar18 != (undefined8 *)0x0) && (pcVar10 = (code *)*puVar18, pcVar10 != (code *)0x0))
        goto LAB_23e7b18f6;
LAB_23e7b1d51:
        FUN_23e915740(param_1,&local_78,lVar9);
        *plVar12 = *plVar12 + -1;
        lVar9 = *plVar12;
        pcVar19 = local_68;
        pcVar17 = local_78;
        plVar8 = plStack_70;
joined_r0x00023e7b1dc9:
        if (lVar9 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
          local_c0._0_4_ = 0x97;
          pcVar10 = _Py_NoneStruct_exref;
          pcVar22 = _PyRuntime_exref;
        }
        else {
          local_c0._0_4_ = 0x97;
          pcVar10 = _Py_NoneStruct_exref;
          pcVar22 = _PyRuntime_exref;
        }
        goto LAB_23e7b050d;
      }
      puVar18 = (undefined8 *)FUN_23a37a020(_DAT_23eed7948,_DAT_23eed7b88);
      if (puVar18 == (undefined8 *)0x0) goto LAB_23e7b1d23;
      pcVar10 = (code *)*puVar18;
LAB_23e7b1d1a:
      if (pcVar10 == (code *)0x0) goto LAB_23e7b1d23;
LAB_23e7b18f6:
      lVar11 = FUN_23e8df050();
      lVar9 = _DAT_23eed7aa0;
      if (lVar11 == 0) goto LAB_23e7b1d51;
      plVar8 = (longlong *)FUN_23e8bc2f0(lVar11,_DAT_23eed7b68);
      if (plVar8 == (longlong *)0x0) {
        pcVar17 = *(code **)(param_1 + 0x60);
        plVar8 = *(longlong **)(param_1 + 0x68);
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar12 = *plVar12 + -1;
        lVar9 = *plVar12;
        goto joined_r0x00023e7b1dc9;
      }
      *(undefined4 *)(plVar4 + 5) = 0x97;
      local_78 = pcVar10;
      plStack_70 = plVar8;
      plVar16 = (longlong *)FUN_23e94ed00(param_1,plVar12,&local_78);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      if (plVar16 == (longlong *)0x0) {
LAB_23e7b1bbd:
        pcVar17 = *(code **)(param_1 + 0x60);
        pcVar19 = *(code **)(param_1 + 0x70);
        local_c0._0_4_ = 0x97;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar22 = _PyRuntime_exref;
        pcVar10 = _Py_NoneStruct_exref;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar8 = *(longlong **)(param_1 + 0x68);
        goto LAB_23e7b050d;
      }
      cVar6 = FUN_23e8d9ac0(plVar1,_DAT_23eed7b20,plVar16);
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        (**(code **)(plVar16[1] + 0x30))(plVar16);
      }
      if (cVar6 == '\0') goto LAB_23e7b1bbd;
      uVar14 = FUN_23a3a0d40(DAT_23ed6cf28);
      *(undefined4 *)(plVar4 + 5) = 0x98;
      plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar14,_DAT_23eed7b90);
      pcVar10 = _Py_NoneStruct_exref;
      if (plVar8 == (longlong *)0x0) {
        pcVar17 = *(code **)(param_1 + 0x60);
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar22 = _PyRuntime_exref;
        local_c0._0_4_ = 0x98;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar8 = *(longlong **)(param_1 + 0x68);
        goto LAB_23e7b050d;
      }
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
LAB_23e7b0e78:
      ppcVar20 = &local_78;
      pcVar19 = (code *)FUN_23e8bc2f0(plVar1,_DAT_23eed7b18);
      if (pcVar19 == (code *)0x0) {
        pcVar17 = *(code **)(param_1 + 0x60);
        pcVar19 = *(code **)(param_1 + 0x70);
        local_c0._0_4_ = 0x9a;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar22 = _PyRuntime_exref;
        pcVar10 = _Py_NoneStruct_exref;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar8 = *(longlong **)(param_1 + 0x68);
        goto LAB_23e7b050d;
      }
      *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
      if (*(longlong *)pcVar19 == 0) {
        (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))(pcVar19);
      }
      pcVar10 = _Py_NoneStruct_exref;
      if (pcVar19 == _Py_NoneStruct_exref) {
        uVar14 = FUN_23a3a0d40(DAT_23ed6cf28);
        *(undefined4 *)(plVar4 + 5) = 0x9b;
        plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar14,_DAT_23eed7b98);
        pcVar22 = _PyRuntime_exref;
        if (plVar8 != (longlong *)0x0) {
          *plVar8 = *plVar8 + -1;
          lVar9 = *plVar8;
          goto joined_r0x00023e7b2012;
        }
        pcVar17 = *(code **)(param_1 + 0x60);
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        local_c0._0_4_ = 0x9b;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar8 = *(longlong **)(param_1 + 0x68);
        goto LAB_23e7b050d;
      }
      uVar14 = FUN_23a3a0d40(DAT_23ed6cf28);
      plVar8 = _DAT_23eed7ba0;
      lVar9 = *(longlong *)(param_1 + 0x10);
      plVar12 = *(longlong **)(lVar9 + 0xe20);
      if (plVar12 == (longlong *)0x0) {
        plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
      }
      else {
        lVar11 = plVar12[3];
        *(int *)(lVar9 + 0xebc) = *(int *)(lVar9 + 0xebc) + -1;
        *(longlong *)(lVar9 + 0xe20) = lVar11;
        *plVar12 = 1;
      }
      pcVar22 = _PyRuntime_exref;
      plVar12[4] = 0;
      lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar22 + 0x1f8) + 0x10) + 0x2e8);
      lVar11 = plVar12[-1];
      puVar18 = *(undefined8 **)(lVar9 + 8);
      *puVar18 = plVar12 + -2;
      plVar12[-2] = lVar9;
      plVar12[-1] = (ulonglong)((uint)lVar11 & 3) | (ulonglong)puVar18;
      *(longlong **)(lVar9 + 8) = plVar12 + -2;
      uVar15 = _DAT_23eed7b18;
      *plVar8 = *plVar8 + 1;
      plVar12[3] = (longlong)plVar8;
      plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar15);
      if (plVar8 == (longlong *)0x0) goto LAB_23e7b1f69;
      pcVar17 = (code *)FUN_23e8bc2f0(plVar8,_DAT_23eed7a98);
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))();
      }
      plVar8 = DAT_23ed6cd28;
      if (pcVar17 == (code *)0x0) goto LAB_23e7b1f69;
      if (DAT_23ed6a4c0 != (longlong *)0x0) goto LAB_23e7b0fd3;
      plVar16 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
    } while (plVar16 == (longlong *)0x0);
    *plVar16 = *plVar16 + 1;
    DAT_23ed6a4c0 = plVar16;
LAB_23e7b0fd3:
    plStack_70 = plVar8;
    local_78 = pcVar17;
    lVar9 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,ppcVar20);
    *(longlong *)pcVar17 = *(longlong *)pcVar17 + -1;
    if (*(longlong *)pcVar17 == 0) {
      FUN_23a334bc0(pcVar17);
    }
    if (lVar9 != 0) {
      plVar12[4] = lVar9;
      plVar16 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        FUN_23a334bc0(plVar12);
      }
      if (plVar16 != (longlong *)0x0) {
        *(undefined4 *)(plVar4 + 5) = 0x9d;
        plVar8 = (longlong *)FUN_23e914090(param_1,uVar14,plVar16);
        *plVar16 = *plVar16 + -1;
        if (*plVar16 == 0) {
          FUN_23a334bc0(plVar16);
        }
        if (plVar8 != (longlong *)0x0) {
          *plVar8 = *plVar8 + -1;
          lVar9 = *plVar8;
joined_r0x00023e7b2012:
          if (lVar9 == 0) {
            FUN_23a334bc0(plVar8);
          }
          pcVar19 = (code *)FUN_23e8bc2f0(plVar1,_DAT_23eed7b20);
          if (pcVar19 == (code *)0x0) {
            pcVar17 = *(code **)(param_1 + 0x60);
            pcVar19 = *(code **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            local_c0._0_4_ = 0x9f;
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcVar22 = _PyRuntime_exref;
            plVar8 = *(longlong **)(param_1 + 0x68);
            goto LAB_23e7b050d;
          }
          *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
          if (*(longlong *)pcVar19 == 0) {
            FUN_23a334bc0(pcVar19);
          }
          if (pcVar19 != pcVar10) {
            uVar15 = FUN_23a3a0d40(DAT_23ed6cf28);
            plVar8 = _DAT_23eed7bb0;
            plVar12 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
            *plVar8 = *plVar8 + 1;
            uVar14 = _DAT_23eed7b20;
            plVar12[3] = (longlong)plVar8;
            plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar14);
            if (plVar8 != (longlong *)0x0) {
              plVar16 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23eed7a98);
              *plVar8 = *plVar8 + -1;
              if (*plVar8 == 0) {
                FUN_23a334bc0(plVar8);
              }
              if (plVar16 != (longlong *)0x0) {
                lVar9 = FUN_23e94f9d0(param_1,plVar16,DAT_23ed6cd28);
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  FUN_23a334bc0(plVar16);
                }
                if (lVar9 != 0) {
                  plVar12[4] = lVar9;
                  plVar16 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    FUN_23a334bc0(plVar12);
                  }
                  if (plVar16 != (longlong *)0x0) {
                    *(undefined4 *)(plVar4 + 5) = 0xa2;
                    plVar8 = (longlong *)FUN_23e914090(param_1,uVar15,plVar16);
                    *plVar16 = *plVar16 + -1;
                    if (*plVar16 == 0) {
                      FUN_23a334bc0(plVar16);
                    }
                    if (plVar8 != (longlong *)0x0) {
                      *plVar8 = *plVar8 + -1;
                      if (*plVar8 != 0) goto LAB_23e7b0a60;
                      goto LAB_23e7b11c2;
                    }
                  }
                  pcVar22 = _PyRuntime_exref;
                  pcVar17 = *(code **)(param_1 + 0x60);
                  pcVar19 = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  local_c0._0_4_ = 0xa2;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar8 = *(longlong **)(param_1 + 0x68);
                  goto LAB_23e7b050d;
                }
              }
            }
            pcVar17 = *(code **)(param_1 + 0x60);
            plVar8 = *(longlong **)(param_1 + 0x68);
            pcVar19 = *(code **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              FUN_23a334bc0(plVar12);
              local_c0._0_4_ = 0xa2;
              pcVar22 = _PyRuntime_exref;
            }
            else {
              local_c0._0_4_ = 0xa2;
              pcVar22 = _PyRuntime_exref;
            }
            goto LAB_23e7b050d;
          }
          uVar14 = FUN_23a3a0d40(DAT_23ed6cf28);
          *(undefined4 *)(plVar4 + 5) = 0xa0;
          plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar14,_DAT_23eed7ba8);
          pcVar22 = _PyRuntime_exref;
          if (plVar8 != (longlong *)0x0) {
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
LAB_23e7b11c2:
              FUN_23a334bc0(plVar8);
            }
LAB_23e7b0a60:
            lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
            plVar8 = *(longlong **)(lVar9 + 0x28);
            plVar4 = (longlong *)plVar8[2];
            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
            *(undefined4 *)(plVar8 + 8) = 0xffffffff;
            if (plVar4 != (longlong *)0x0) {
              plVar8[2] = 0;
              *plVar4 = *plVar4 + -1;
              if (*plVar4 == 0) {
                (**(code **)(plVar4[1] + 0x30))();
              }
            }
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            *(longlong *)pcVar10 = *(longlong *)pcVar10 + 1;
            plVar8[0xf] = 0;
            *plVar1 = *plVar1 + -1;
            if (*plVar1 == 0) {
              (**(code **)(plVar1[1] + 0x30))(plVar1);
            }
            return pcVar10;
          }
          pcVar17 = *(code **)(param_1 + 0x60);
          pcVar19 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          local_c0._0_4_ = 0xa0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar8 = *(longlong **)(param_1 + 0x68);
          goto LAB_23e7b050d;
        }
      }
      pcVar17 = *(code **)(param_1 + 0x60);
      pcVar19 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      local_c0._0_4_ = 0x9d;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar8 = *(longlong **)(param_1 + 0x68);
      goto LAB_23e7b050d;
    }
LAB_23e7b1f69:
    pcVar17 = *(code **)(param_1 + 0x60);
    plVar8 = *(longlong **)(param_1 + 0x68);
    pcVar19 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    local_c0._0_4_ = 0x9d;
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
      local_c0._0_4_ = 0x9d;
    }
  } while( true );
LAB_23e7b0494:
  pcVar17 = *(code **)(param_1 + 0x60);
  pcVar19 = *(code **)(param_1 + 0x70);
  local_c0._0_4_ = 0x96;
  *(undefined8 *)(param_1 + 0x70) = 0;
  pcVar22 = _PyRuntime_exref;
  pcVar10 = _Py_NoneStruct_exref;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar8 = *(longlong **)(param_1 + 0x68);
  goto LAB_23e7b050d;
}
